#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ÅÐ¶ÏÇ°×º

int main() {
    vector<int> ivec1 = {0, 1, 1, 2, 1};
    vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};
    bool flag = true;
    int minSize = 0;
    (ivec1.size() <= ivec2.size()) ? minSize = ivec1.size() : minSize = ivec2.size();

    for (int i = 0; i != minSize; ++ i) {
        if (ivec1[i] != ivec2[i]) {
            flag = false;
        }
    }

    flag ? (cout << "ÊÇ" << endl) : (cout << "·ñ" << endl);

    return 0;
}
