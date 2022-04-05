#include <iostream>
#include <string>

using namespace std;

// 将string中的oldVal替换为newVal
// 使用迭代器、insert、erase

void repacle_val(string& s, const string& oldVal, const string& newVal) {
    auto old_s = oldVal.size(), new_s = newVal.size();
    auto iter = s.cbegin();

    while (iter != s.cend()) {
        auto cp_iter = iter;
        auto old_iter = oldVal.cbegin();
        // 寻找匹配字符串
        for (; old_iter != oldVal.cend() && cp_iter != s.cend(); ++ old_iter, ++ cp_iter) {
            if (*cp_iter != *old_iter) {
                break;
            }
        }
        if (cp_iter - iter == old_s) {
            iter = s.erase(iter, cp_iter);  // 迭代器可能已经失效
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            iter += new_s;
        }
        else {
            ++ iter;
        }
    }
}

int main() {
    string s("jfls fljf jflwjlf lfejthofjwle wflljfow thojfltho fwwoothor fwthothojfllwl");
    cout << s << endl;
    
    repacle_val(s, "tho", "though");
    cout << s << endl;

    return 0;
}
