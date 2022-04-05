#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

// 背包问题，利用有限的容量获得最大价值

class Bag {
    /* 单元格 */
    public:
        double value = 0;  // 当前背包总价值
        set<string> goods;  // 当前背包内物品

        // 构造函数
        Bag() = default;
        Bag(double& v, set<string>& g): value(v), goods(g) {}

        // 成员函数
        void add(double& v, string& g) {
            value += v;
            goods.insert(g);
        }
};


class Good {
    /* 每种货物的属性 */
    public:
        string gname;   // 名字
        double price = 0;  // 该货物价值
        double cost = 0;   // 占用背包空间

        // 构造函数
        Good() = default;
        Good(const string& n, const double& p, const double& c): gname(n), price(p), cost(c) {}
};


Bag bag_alg(vector<Good>& goods, double& dist, double& cap) {
    /* 有限空间价值最大化（背包问题） */
    size_t sz_goods = goods.size(), sz_cap = cap / dist + 1;
    // 创建网格
    Bag mesh[sz_goods][sz_cap];
    // 先填充第一行
    double current_cap = 0;
    for (size_t j = 0; j != sz_cap; ++ j) {
        current_cap = (j + 1) * dist;   // 当前单元格容量
        // 当前货物能否放下？
        if (goods[0].cost <= current_cap) {
            mesh[0][j].add(goods[0].price, goods[0].gname); // 更新当前单元格
        }
    }

    // 遍历网格（从第二行开始）
    for (size_t i = 1; i != sz_goods; ++ i) {
        for (size_t j = 0; j != sz_cap; ++ j) {
            current_cap = (j + 1) * dist;
            if (goods[i].cost < current_cap) {
                // 当前货物价值+剩余空间价值>上一行的价值（该容量下的最大价值）
                size_t sz = goods[i].cost / dist + 1;
                if (mesh[i - 1][j - sz].value + goods[i].price > mesh[i - 1][j].value) {
                    // 更新当前单元格为剩余空间信息+当前货物信息
                    mesh[i][j] = mesh[i - 1][j - sz];
                    mesh[i][j].add(goods[i].price, goods[i].gname);
                }
                else {
                    mesh[i][j] = mesh[i - 1][j];    // 保持当前容量的最大价值
                }
            }
            else if (goods[i].cost == current_cap) {
                // 如果当前货物恰好沾满当前空间
                if (goods[i].price > mesh[i - 1][j].value) {
                    mesh[i][j].add(goods[i].price, goods[i].gname);
                }
                else {
                    mesh[i][j] = mesh[i - 1][j];
                }
            }
            else {
                // 放不下，保持当前容量的最大价值
                mesh[i][j] = mesh[i - 1][j];
            }
        }
    }

    // 返回最后一个Bag
    return mesh[sz_goods - 1][sz_cap - 1];
}

int main() {
    // 创建货物
    vector<Good> mygoods{
        Good("jita", 15, 0.3),
        Good("wang", 21, 0.5),
        Good("wzx", 25, 0.7),
        Good("zi", 18, 1.0),
        Good("xu", 30, 1.5),
        Good("laptap", 20, 2.0),
        Good("sound", 30, 3.0)
    };

    // 根据货物情况，设定背包可用容量间隔
    double dist = 0.1;
    // 背包总容量
    double cap = 6.0;

    auto result = bag_alg(mygoods, dist, cap);

    cout << "最大总价值：" << endl;
    cout << result.value << endl;
    cout << "背包内货物：" << endl;
    for (auto& g : result.goods) {
        cout << g << "\t";
    }
    cout << endl;

    /* 这是什么情况？
    double a = 6.0, b = 0.1;
    size_t t;
    t = a / b;
    cout << t << endl;  // 输出59
    t = 6.0 / 0.1;
    cout << t << endl;  // 输出60
    */

    return 0;
}
