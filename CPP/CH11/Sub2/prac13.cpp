#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

// 使用map保存家庭，每个家庭保存到一个vector，保存姓名和生日，使用pair

int main() {
    map<string, vector<pair<string, string>>> families;
    /* 添加新的家庭 */
    families["wang"] = {
        {"zuoqing", "0916"},
        {"liqing", "0729"},
        {"zixu", "0712"}
    };
    families["li"] = {
        {"li1", "0913"},
        {"li2", "1209"}
    };
    families["zhang"] = {
        {"zh1", "0822"},
        {"zh2", "0621"}
    };
    /* 向已有家庭添加新成员 */
    families["wang"].push_back(make_pair("wife", "0303"));

    /* 输出 */
    for(auto& f : families) {
        cout << f.first << ": \n\t";
        for(auto& n : f.second) {
            cout << n.first << ": " << n.second << "\n\t";
        }
        cout << endl;
    }

    return 0;
}
