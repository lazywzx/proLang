#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// list<char*> ¸³Öµ¸øvector<string>

int main() {
    list<char*> lc{"This ", "is ", "a ", "list char*"};
    vector<string> vs{"The ", "second", "string"};

    vs.assign(++ lc.begin(), ++ ++ lc.begin());

    for (auto& s : vs) {
        cout << s;
    }
    cout << endl;

    return 0;
}
