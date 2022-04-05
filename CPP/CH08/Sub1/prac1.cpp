#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

// 读取与操作流状态

istream& func_stream(istream& i) {
    while (!i.eof()) {
        string tmp("");
        i >> tmp;
        cout << tmp;
    }
    i.clear();
    return i;
}

int main() {
    cout << "输入内容：" << endl;
    func_stream(cin);

    return 0;
}
