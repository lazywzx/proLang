#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

// 将第二个string插入到forward_list中第一个string之后，
// 若没有找到第一个string，将第二个string放到forward_list末尾

void process(forward_list<string>& fls, const string& s1, const string& s2) {
    auto curr = fls.cbegin();
    auto curr_b = curr;
    bool flag = false;

    for (; curr != fls.cend(); ++ curr, ++ curr_b) {
        if (*curr == s1) {
            curr = fls.insert_after(curr, s2);
            flag = true;
        }

        if ((++ curr_b) == fls.cend() && !flag) {
            fls.insert_after(curr, s2);
        }
        else {
            curr_b = curr;
        }
    }
}

int main() {
    forward_list<string> fls{"s1", "s2", "s3", "s4", "s2", "s2", "s3"};
    string s1 = "s2";
    string s2 = "ss";

    process(fls, s1, s2);
    for (auto& i : fls) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
