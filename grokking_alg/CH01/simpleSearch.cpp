#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 简单查找

vector<string>::const_iterator simpleSearch(const vector<string>& vs, const string& word) {
    /* 传入容器不要有序 */
    for (auto iter = vs.cbegin(); iter != vs.cend(); ++ iter) {
        if (*iter == word)
            return iter;
    }
    // 没找到返回尾后迭代器
    return vs.cend();
}

int main() {
    vector<string> vs{ "dianzi",  "kexue", "21S", "tangshan", "wang", "HIT", "xi", "zi", "xinxi", "hebei", "xu", "xueyuan", "yu", "gongcheng"};
    auto iter = simpleSearch(vs, "wan");
    if (iter != vs.cend()) {
        cout << "找到，位置：" << iter - vs.cbegin() << endl;
    }
    else {
        cout << "没找到" << endl;
    }

    return 0;
}

