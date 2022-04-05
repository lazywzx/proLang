#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

// 使用map保存单词及其行号，list保存行号

int main() {
    map<string, list<int>> words{
        {"wang", {1, 3, 6, 8, 9}},
        {"zhang", {1, 5, 6, 9, 10}}
    };

    for (auto& word : words) {
        cout << word.first << ":\n\t";
        for(auto& n : word.second) {
            cout << n << "\n\t";
        }
        cout << endl;
    }

    return 0;
}