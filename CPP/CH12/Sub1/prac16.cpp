#include <memory>
#include <new>

using namespace std;

// 观察拷贝或赋值unique_ptr的报错信息

int main() {
    unique_ptr<string> p1(new string("hhh"));
    unique_ptr<string> p2(p1);
    unique_ptr<string> p3;
    p3 = p1;

    return 0;
}
