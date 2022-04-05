#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Êý×é¿½±´
int iarr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int ciarr[10] = {};

// ÈÝÆ÷¿½±´
vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> civec = ivec;

int main() {
    for (unsigned int i = 0; i < 10; ++ i) {
        ciarr[i] = iarr[i];
    }
    
    for (auto &n : ciarr) {
        cout << n << "\t";
    }
    cout << endl;

    for (auto &nv : civec) {
        cout << nv << "\t";
    }
    cout << endl;

    return 0;
}
