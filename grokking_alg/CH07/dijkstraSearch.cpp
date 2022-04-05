#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

// 狄克斯特拉算法，搜索无环正权图最短路径

string find_lowest_cost_node(map<string, unsigned>& costs, set<string>& processed) {
    /* 从未处理的节点中寻找最小开销节点 */
    unsigned lowest_cost = -1;
    string lowest_cost_node("");
    // 遍历所有节点
    for (auto& n : costs) {
        if (n.second < lowest_cost) {
            if (processed.find(n.first) == processed.cend()) {
                // 更小且未处理
                lowest_cost = n.second;
                lowest_cost_node = n.first;
            }
        }
    }

    return lowest_cost_node;
}

void dijkstraSearch(map<string, map<string, unsigned>>& graph, map<string, unsigned>& costs, map<string, string>& parents) {
    /* 查找无环正权图最短路径 */
    set<string> processed;  // 已处理的节点
    auto node = find_lowest_cost_node(costs, processed);    // 未处理的最小开销节点
    while (!node.empty()) {
        auto cost = costs[node];    // 最小开销
        auto neighbors = graph[node];   // 该节点的邻居
        // 遍历所有邻居
        for (auto& n : neighbors) {
            auto new_cost = cost + n.second;    // 去往该邻居总共的开销
            if (new_cost < costs[n.first]) {
                // 如果这条路线的开销小于原来的开销
                costs[n.first] = new_cost;  // 更新开销，保持最短路径
                parents[n.first] = node;    // 当前节点作为该邻居的父节点
            }
        }
        // 当前节点的所有邻居都处理完，标记当前节点为已处理
        processed.insert(node);
        node = find_lowest_cost_node(costs, processed); // 处理剩余节点
    }
}

void print(map<string, unsigned>& costs, map<string, string>& parents, string& beg, string& fin) {
    /* 输出结果 */
    cout << "最短路径开销：" << costs[fin] << endl;
    cout << "最短路径：\n";
    string key = fin;
    // 倒序输出
    cout << key << "<-";
    while (parents[key] != beg) {
        key = parents[key];
        cout << key << "<-";
    }
    cout << beg << endl;
}

int main() {
    map<string, map<string, unsigned>> graph;
    graph["beg"] = {{"A", 5}, {"B", 2}};
    graph["A"] = {{"C", 4}, {"D", 2}};
    graph["B"] = {{"A", 8}, {"D", 7}};
    graph["C"] = {{"D", 6}, {"fin", 3}};
    graph["D"] = {{"fin", 1}};
    graph["fin"] = {};  // = {{}}这样写认为有一个元素，不为空！！！

    map<string, unsigned> costs;
    // 不能一步到达的计无穷大
    costs["A"] = 5;
    costs["B"] = 2;
    costs["C"] = -1;
    costs["D"] = -1;
    costs["fin"] = -1;

    map<string, string> parents;
    // 初始设定全部节点的父节点为起点(除终点外)
    parents["A"] = "beg";
    parents["B"] = "beg";
    parents["C"] = "beg";
    parents["D"] = "beg";
    parents["fin"] = "";

    dijkstraSearch(graph, costs, parents);
    string beg = "beg", fin = "fin";
    print(costs, parents, beg, fin);    // 注意参数顺序!!!

    return 0;
}
