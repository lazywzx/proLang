#include <iostream>
#include <string>

using namespace std;

// 替换string中的oldVal为newVal
// 使用下标、replace

void replace_val(string& s, const string& oldVal, const string& newVal) {
    auto old_s = oldVal.size(), new_s = newVal.size();
    decltype(s.size()) index = 0, old_i = 0;

    while (index != s.size()) {
        auto cp_i = index;
        old_i = 0;
        // 查找匹配字符串
        for (; old_i != old_s && cp_i != s.size(); ++ old_i, ++ cp_i) {
            if (s[cp_i] != oldVal[old_i]) {
                break;
            }
        }

        if (cp_i - index == old_s) {
            s.replace(index, old_s, newVal);
            index += new_s; // 跳过新插入字符串
        }
        else {
            ++ index;
        }
    }
}

int main() {
    string s("jfls fljf jflwjlf lfejthofjwle wflljfow thojfltho fwwoothor fwthothojfllwl");
    cout << s << endl;

    replace_val(s, "tho", "though");
    cout << s << endl;

    return 0;
}
