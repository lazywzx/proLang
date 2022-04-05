#include <iostream>
#include <set>
#include "Sales_data.h"

using namespace std;

// 不使用decltype定义bookstore

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
    auto iter = bookstore.begin();

}
