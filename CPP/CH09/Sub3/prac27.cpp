#include <iostream>
#include <forward_list>

using namespace std;

// É¾³ıforward_listÖĞµÄÆæÔªËØ

int main() {
    forward_list<int> fli{1, 2, 3, 4, 5, 6};

    auto prev = fli.cbefore_begin();
    auto curr = fli.cbegin();
    while (curr != fli.cend()) {
        if (*curr % 2) {
            curr = fli.erase_after(prev);
        }
        else {
            prev = curr;
            ++ curr;
        }
    }

    cout << "forward_list: " << endl;
    for (auto& i : fli) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}