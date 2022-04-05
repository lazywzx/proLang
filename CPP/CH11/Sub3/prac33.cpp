#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// 单词转换程序

/* 构建单词转换映射关系 */
map<string, string> buildMap(ifstream& infile) {
    map<string, string> word_map;
    string key, value;
    while (infile >> key) {
        getline(infile, value);
        word_map[key] = value.substr(1);
    }

    return word_map;
}

/* 单词转换 */
string trans(string w, map<string, string>& m) {
    auto iter = m.find(w);
    if (iter != m.cend()) {
        return iter->second;
    }
    else {
        return w;
    }
}

/* 总体函数 */
void trans_word(ifstream& mapfile, ifstream& transfile) {
    auto wordmap = buildMap(mapfile);
    // 读取transfile
    string line, word;
    while (getline(transfile, line)) {
        istringstream words(line);
        while (words >> word) {
            cout << trans(word, wordmap) << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    ifstream mf(argv[2]), tf(argv[4]);
    if (mf && tf) {
        trans_word(mf, tf);
    }
    else {
        cerr << "文件打开失败" << endl;
    }

    return 0;
}
