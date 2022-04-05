#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 用cin读入一组整数存入一个vector对象
int main() {
    string i;
    vector<string> ivec;
    while (cin >> i) {
        ivec.push_back(i);
    }
    
    return 0;
}
