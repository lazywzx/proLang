#include <iostream>
#include <string>

using namespace std;

// 将前缀和后缀添加到名字中
// 使用迭代器、insert、append

string name(string& s, const string& before, const string& after) {
    string modi_name = " " + s + " ";
    modi_name.insert(modi_name.cbegin(), before.cbegin(), before.cend());
    modi_name.append(after);

    return modi_name;
}

int main() {
    string myname("wangzixu");
    string modi_name = name(myname, "Mr.", "First");
    cout << modi_name << endl;

    return 0;
}
