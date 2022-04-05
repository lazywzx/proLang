#include <iostream>
#include <list>
#include <forward_list>
#include <string>

using namespace std;

// listºÍforward_listÈİÆ÷£¬É¾³ıÅ¼ÔªËØ£¬¸³ÖµÆæÔªËØ

int main() {
    list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int> fli{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto iter = fli.cbegin();
    auto before_iter = fli.cbefore_begin();
    while (iter != fli.cend()) {
        if (*iter % 2) {
            iter = fli.insert_after(before_iter, *iter++);
            ++ iter;
            before_iter = iter;
            ++ iter;
        }
        else {
            iter = fli.erase_after(before_iter);
        }
    }

    for (auto& i : fli) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
