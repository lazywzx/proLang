#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 容器中的字符串均表示整数值，求和
// 表示浮点数值

int main() {
    vector<string> vsi{"12", "23", "34", "45"};
    vector<string> vsf{"12.3", "23.4", "34.5", "45.6"};

    int sumi = 0;
    float sumf = 0.0;
    for (auto& i : vsi) {
        sumi += stoi(i);
    }

    for (auto& f : vsf) {
        sumf += stof(f);
    }

    cout << sumi << "\t" << sumf << endl;

    return 0;
}
