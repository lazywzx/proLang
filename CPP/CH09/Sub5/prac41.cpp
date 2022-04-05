#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 从vector<char>初始化string

int main() {
    const vector<char> vc{'a', 'b', 'c'};
    string s(vc.cbegin(), vc.cend());

    cout << s << endl;

    return 0;
}
