#include <iostream>

using std::cout;
using std::endl;

// 数组传参越界问题

void print_nums(const int nums[5]) {
    for (size_t i = 0; i != 5; ++ i) {
        cout << nums[i] << "\t";
    }
    cout << endl;
}

int main() {
    int nums[3] = {0, 1, 2};
    print_nums(nums);

    return 0;
}
