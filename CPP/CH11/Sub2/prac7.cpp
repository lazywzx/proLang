#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 使用map保存家庭，每个家庭保存到一个vector，保存姓名

int main() {
    map<string, vector<string>> families;
    /* 添加新的家庭 */
    families["wang"] = {"zuoqing", "liqing", "zixu"};
    families["li"] = {"li1", "li2"};
    families["zhang"] = {"zh1", "zh2"};
    /* 向已有家庭添加新成员 */
    families["wang"].push_back("wife");

    /* 输出 */
    for(auto& f : families) {
        cout << f.first << ": \n\t";
        for(auto& n : f.second) {
            cout << n << "\n\t";
        }
        cout << endl;
    }

    return 0;
}
