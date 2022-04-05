#include <iostream>
#include <string>

using namespace std;

// 将前缀和后缀添加到名字中
// 使用位置和长度管理string、使用insert

string name(string& s, const string& before, const string& after) {
    string modi_name = " " + s + " ";
    modi_name.insert(0, before);
    modi_name.insert(modi_name.size(), after);

    return modi_name;
}

int main() {
    string myname("wangzixu");
    string modi_name = name(myname, "Mr.", "First");

    cout << modi_name << endl;
    return 0;
}