#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// ��cin����һ����������һ��vector����
int main() {
    string i;
    vector<string> ivec;
    while (cin >> i) {
        ivec.push_back(i);
    }
    
    return 0;
}
