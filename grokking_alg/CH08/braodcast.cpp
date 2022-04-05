#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// 贪婪/近似算法，广播台问题

void states_stations(set<string>& states, map<string, set<string>>& stations, set<string>& stations_set) {
    /* 寻找能够覆盖全部州的最小广播台集合 */
    auto mystates = states;
    auto mystations = stations;
    while (!mystates.empty()) {
        // 还有未覆盖的州
        string best_station("");    // 交集最多的电台
        size_t len = 0; // 交集元素数
        for (auto& s : mystations) {
            // 遍历每个电台
            set<string> co_states;
            // 获得交集
            auto station = s.second;
            set_intersection(station.cbegin(), station.cend(), mystates.cbegin(), mystates.cend(), inserter(co_states, co_states.begin()));
            // 找到最长的交集
            if (co_states.size() > len) {
                best_station = s.first;
                len = co_states.size();
            }
        }
        // 差集，结果是未覆盖的州
        set<string> covered_states;
        set_difference(mystates.cbegin(), mystates.cend(), mystations[best_station].cbegin(), mystations[best_station].cend(), inserter(covered_states, covered_states.begin()));
        mystates = covered_states;
        stations_set.insert(best_station);  // 当前采用的电台
        mystations.erase(best_station); // 删除所采用的电台
    }
}


int main() {
    // 州集合
    set<string> states{"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
    // 电台覆盖情况
    map<string, set<string>> stations;
    stations["kone"] = {"id", "nv", "ut"};
    stations["ktwo"] = {"wa", "id", "mt"};
    stations["kthree"] = {"or", "nv", "ca"};
    stations["kfour"] = {"nv", "ut"};
    stations["kfive"] = {"ca", "az"};

    // 使用的电台集合
    set<string> emp_sta;
    states_stations(states, stations, emp_sta);

    // 打印结果
    cout << "采用的电台" << endl;
    for (auto& s : emp_sta) {
        cout << s << "\t";
    }
    cout << endl;

    return 0;
}
