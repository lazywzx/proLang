#include <iostream>
#include <string>

using namespace std;

// 寻找最长的不包含上/下出头部分的单词

int main() {
    string word;
    string a_descender("bdfghijklpqty");

    cout << "输入一个小写字母单词：" << endl;
    while (cin >> word) {
        string::size_type max_pos = 0, pos = 0, max_dist = 0, last_pos = 0;
        while ((pos = word.find_first_of(a_descender, pos)) != string::npos) {
            if (pos - last_pos > max_dist) {
                max_pos = last_pos + 1;
                max_dist = pos - last_pos - 1;
            }
            last_pos = pos;
            ++ pos;
        }

        // 输出结果
        cout << word.substr(max_pos, max_dist) << endl;
    }

    return 0;
}
