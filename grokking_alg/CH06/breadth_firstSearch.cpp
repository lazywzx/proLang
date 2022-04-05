#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <iterator>

using namespace std;

// 广度优先搜索

inline bool isThis(const string& node) {
    /* 根据obj的某个属性判断是否找到 */
    return (node[node.size() - 1] == 'W') ? true : false;
}

string breadth_firstSearch(map<string, set<string>>& graph, string& start_node, map<string, string>& parents) {
    /* 给定图和起始节点，返回距离最近的满足条件的节点和最短路径 */
    deque<string> search_queue; // 查找队列
    set<string> searched_node;  // 已查找过的节点，避免重复查找
    // 将起始节点的邻居加入队列
    search_queue.insert(search_queue.cend(), graph[start_node].cbegin(), graph[start_node].cend());
    // 设置子节点的父节点
    for (auto& n : graph[start_node]) {
        parents.insert({n, start_node});
    }
    // 只要队列不为空
    while (search_queue.size()) {
        auto node = search_queue.front();
        search_queue.pop_front();   // 弹出首元素
        if (searched_node.find(node) == searched_node.cend()) {
            if (isThis(node)) {
                return node;
            }
            else {
                // 此节点的邻居加入队列
                search_queue.insert(search_queue.cend(), graph[node].cbegin(), graph[node].cend());
                searched_node.insert(node); // 标记该节点为已查询
                // 此节点的邻居的父节点为此节点
                for (auto& n : graph[node]) {
                    parents.insert({n, node});
                }
            }
        }
    }
    // 没找到返回空字符串
    return "";
}

int main() {
    /* 创建图 */
    map<string, set<string>> graph;
    // 单向图
    graph["wang"] = {"zi", "xu", "wzx"};    // 没有的键会自动创建
    graph["zi"] = {"li", "zhang_W"};
    graph["xu"] = {"wu", "min", "han"};
    graph["wzx"] = {"min", "zeng"};
    graph["li"] = {"zhang_W", "ma"};
    graph["zhang_W"] = {"wu"};
    graph["wu"] = {"guan_W"};
    graph["min"] = {"wei"};
    graph["han"] = {"ma"};
    graph["zeng"] = {};
    graph["ma"] = {};
    graph["guan_W"] = {};
    graph["wei"] = {};

    // 记录路径
    map<string, string> parents;

    // 起始节点
    string s_node("wang");
    
    auto result = breadth_firstSearch(graph, s_node, parents);
    if (!result.empty()) {
        cout << "找到，最近节点是：" << result << endl;
        // 逆序输出
        cout << "最短路径：" << endl;
        cout << result << "<-";
        string key = result;
        while (parents[key] != s_node) {
            key = parents[key];
            cout << key << "<-";
        }
        cout << s_node << endl;
    }
    else {
        cout << "没找到" << endl;
    }

    return 0;
}
