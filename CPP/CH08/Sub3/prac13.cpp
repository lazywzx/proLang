#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 电话号码处理程序

/* 个人电话号码类 */
class Phone {
    public:
        string name;    // 姓名
        vector<string> phone_num;   // 电话号码
};

/* 读取文件 */
void read_data(const string& path, vector<Phone>& peo) {
    ifstream infile(path);
    if (infile) {
        string line, word;
        Phone tmp;
        istringstream l;
        // 读取每一行
        while (getline(infile, line)) {
            l.str(line);
            l >> word;  // 读取姓名
            tmp.name = word;
            tmp.phone_num = {}; // 清空上一个人的数据
            while (l >> word) {
                tmp.phone_num.push_back(word);  // 读取所有电话号码
            }
            peo.push_back(tmp);  // 存储每个人的数据
            l.clear();
        }
    }
    else {
        cerr << "File open fail!" << endl;
    }
}

/* 合法性验证 */
inline bool vaild(const string& num) {
    return (num.size() == 11) ? true : false;
}

/* 格式转换 */
inline string formate(const string& num) {
    return "+86" + num;
}

/* 合法数据输出到文件 */
inline void write_data(const string& path, const string& info) {
    ofstream outfile(path, ofstream::app);
    outfile << info << endl;
}

/* 非法数据打印到终端 */
inline void print_data(const string& info) {
    cout << "BAD DATA: " << info << endl;
}

/* 主要处理函数 */
void process(const vector<Phone>& people, const string& outpath) {
    cout << "开始处理..." << endl;
    // 遍历每个人
    for (const auto& p : people) {
        ostringstream good, bad;
        for (const auto& n : p.phone_num) {
            // 验证这个人所有电话号码
            if (vaild(n)) {
                // 格式正确，转换格式
                good << " " << formate(n);
            }
            else {
                bad << " " << n;
            }
        }
        // 合法数据写到文件，非法数据打印到终端
        write_data(outpath, p.name + " " + good.str());
        if (!bad.str().empty())
            print_data(p.name + " " + bad.str());
    }
    cout << "处理完成！" << endl;
}

/* 主函数 */
int main(int argc, char* argv[]) {
    // 保存所有人的信息的原始数据
    vector<Phone> people{};
    read_data(argv[2], people);
    process(people, argv[4]);

    return 0;
}
