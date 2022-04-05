#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 使用multimap保存家庭，每个家庭保存到一个vector，保存姓名

int main() {
    multimap<string, vector<string>> families;
    /* 添加新的家庭 */
    families.insert({"wang", {"zuoqing", "liqing", "zixu"}});
    families.insert({"li", {"li1", "li2"}});
    families.insert({"zhang", {"zh1", "zh2"}});
    /* 向已有家庭添加新成员 */
    families.insert({"wang", {"wife"}});

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
