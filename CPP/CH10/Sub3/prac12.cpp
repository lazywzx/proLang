#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

// 比较两个Sales_data对象的isbn()，并排序包含Sales_data的vector

bool compareIsbn(Sales_data& s1, Sales_data& s2) {
    return s1.isbn() < s2.isbn();
}

int main() {
    vector<Sales_data> vs{};
    vs.push_back(Sales_data("x-2232"));
    vs.push_back(Sales_data("x-2231"));
    vs.push_back(Sales_data("x-2233"));
    vs.push_back(Sales_data("x-2232"));
    vs.push_back(Sales_data("x-2235"));
    vs.push_back(Sales_data("x-2231"));

    sort(vs.begin(), vs.end(), compareIsbn);

    for (auto& s : vs) {
        print(cout, s) << endl;
    }

    return 0;
}
