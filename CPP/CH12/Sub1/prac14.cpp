#include <memory>

using namespace std;

// 定义自己的用shared_ptr管理的conncetion
// 使用lambda代替end_connection()

struct destination;
struct connection;
connection connect(destination*);
void disconnect(connection);

auto ec = [](connection *p) {
    disconnect(*p);
};

/*
void end_connection(connection *p) {
    disconnect(*p);
}
*/

void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, ec);
}


