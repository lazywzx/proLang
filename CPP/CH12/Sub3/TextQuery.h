#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 声明
class TextQuery;
class QueryResult;

/************TextQuery类**************/
class TextQuery {
    private:
        vector<string> text;    // 保存文本，按行保存
        map<string, set<int>> word_map; // 每个单词的行号
        map<string, int> word_cnt;  // 每个单词出现的次数
        // 每行文本通过set保存的行号作为下标从vector中读出
    public:
        /* 构造函数 */
        TextQuery();
        TextQuery(ifstream&);
        /* 成员函数 */
        QueryResult query(const string&); 
};
/********** 构造函数 *****************/
TextQuery::TextQuery(): text({}), word_map({}), word_cnt({}) {};
TextQuery::TextQuery(ifstream& infile) {
    if (infile) {
        string line, word;
        int num = 0;    // 行号
        while (getline(infile, line)) {
            text.push_back(line);   // 保存该行
            istringstream iss(line);
            while (iss >> word) {
                // 读取该行每个单词
                /* 格式化单词，去掉标点符号 */
                if (ispunct(*(word.crbegin()))) {
                    word.erase(word.size() - 1);
                }
                // 新判断是否已有该单词
                if (word_map.find(word) == word_map.end()) {
                    word_map.insert({word, {num}}); // 新单词
                }
                else {
                    word_map[word].insert(num); // 新行号
                }
                ++ word_cnt[word];  // 单词出现次数
            }
            ++ num;
        }
    }
    else {
        throw runtime_error("文件打开失败");
    }
}


/***********QueryResult类**************/
class QueryResult {
    friend QueryResult TextQuery::query(const string&);
    friend void print(ostream&, const QueryResult&);
    private:
        set<int> line_num;  // 该单词出现的行号
        int word_cnt;   // 该单词出现次数
        vector<string> result_text; // 该单词所在行的文本
    public:
        /* 构造函数 */
        QueryResult();
};
/* 构造函数 */
QueryResult::QueryResult(): word_cnt(0), line_num({}), result_text({}) {};


/*********成员函数**************/
// 查询
QueryResult TextQuery::query(const string& word) {
    QueryResult result;
    /* 先判断要查询的单词是否存在 */
    if (word_cnt.find(word) != word_cnt.end()) {
        auto res_set = word_map[word];  // 行号列表
        result.line_num.insert(res_set.cbegin(), res_set.cend());
        // 出现次数
        result.word_cnt = word_cnt[word];
        // 所在行文本
        for (auto& n : res_set) {
            result.result_text.push_back(text[n]);
        }
    }
    else {
        cerr << "查无此词" << endl;
    }
    
    return result;
}

/**********非成员函数***********/
// 打印
void print(ostream& os, const QueryResult& qr) {
    if (qr.word_cnt != 0) {
        cout << "查询结果：" << endl;
        cout << "出现次数：" << qr.word_cnt << endl;
        cout << "所在行：" << endl;
        auto sb = qr.line_num.cbegin();
        auto vb = qr.result_text.cbegin();
        for (; sb != qr.line_num.cend(); ++ sb, ++ vb) {
            // 行号从1开始
            cout << "\t(line " << *sb + 1 << ") " << *vb << endl;
        }
    }
}

#endif
