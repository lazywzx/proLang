#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::strcmp;

// 比较两个string对象，比较两个C风格字符串
string s1 = "this is string1.";
string s2 = "this is string1.";
string s3 = "this is string3.";

const char c1[] = "this is c1.";
const char c2[] = "this is c1.";
const char c3[] = "this is c3.";

int main() {
    cout << "string" << endl;
    if (s1 == s2) {
        cout << "s1 == s2" << endl;
    }
    else if (s1 < s2) {
        cout << "s1 < s2" << endl;
    }
    else {
        cout << "s1 > s2" << endl;
    }
    if (s1 == s3) {
        cout << "s1 == s3" << endl;
    }
    else if (s1 < s3) {
        cout << "s1 < s3" << endl;
    }
    else {
        cout << "s1 > s3" << endl;
    }
    if (s2 == s3) {
        cout << "s2 == s3" << endl;
    }
    else if (s2 < s3) {
        cout << "s2 < s3" << endl;
    }
    else {
        cout << "s2 > s3" << endl;
    }

    cout << "C风格字符串" << endl;
    auto r = strcmp(c1, c2);
    if (r == 0) {
        cout << "c1 == c2" << endl;
    }
    else if (r < 0) {
        cout << "c1 < c2" << endl;
    }
    else {
        cout << "c1 > c2" << endl;
    }
    r = strcmp(c1, c3);
    if (r == 0) {
        cout << "c1 == c3" << endl;
    }
    else if (r < 0) {
        cout << "c1 < c3" << endl;
    }
    else {
        cout << "c1 > c3" << endl;
    }
    r = strcmp(c2, c3);
    if (r == 0) {
        cout << "c2 == c3" << endl;
    }
    else if (r < 0) {
        cout << "c2 < c3" << endl;
    }
    else {
        cout << "c2 > c3" << endl;
    }

    return 0;
}

