#ifndef STRBLOB_H
#define STRBLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

// 声明
class StrBlob;
class StrBlobPtr;

/******************************StrBlob类******************************/
class StrBlob {
    /* 友元声明 */
    friend class StrBlobPtr;
    /* 类型别名 */
    public:
        typedef vector<string>::size_type sz;
    /* 私有 */
    private:
        /* 保存string的vector的智能指针 */
        shared_ptr<vector<string>> data;
        /* 检查索引是否合法 */
        void check(sz, const string&) const;
    /* 公有 */
    public:
        /* 构造函数 */
        StrBlob();
        StrBlob(initializer_list<string>);
        sz size() const {
            return data->size();
        }
        bool empty() const {
            return data->empty();
        }
        /* 添加和删除元素 */
        void push_back(const string& s) {
            data->push_back(s);
        }
        void pop_back();
        /* 元素访问 */
        string& front();
        const string& front() const;
        string& back();
        const string& back() const;
        /* 返回首元素和尾后元素指针 */
        StrBlobPtr begin();
        StrBlobPtr end();
};

/************************StrBlobPtr类**************************/
class StrBlobPtr {
    private:
        weak_ptr<vector<string>> wptr;
        size_t curr;
        // 成员函数
        shared_ptr<vector<string>> check(size_t, const string&) const;
    
    public:
        // 构造函数
        StrBlobPtr(): curr(0) {}
        StrBlobPtr(StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) {}
        // 解引用和递增成员函数
        string& deref() const;
        StrBlobPtr& incr();
};

/***************************成员函数的定义*****************************************/
/*********StrBlob类***************/
/* 构造函数的定义 */
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

/* 成员函数的定义 */
void StrBlob::check(sz i, const string& msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

/* 返回首元素和尾后元素指针 */
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

/***********StrBlobPtr类*************/
/* 检查指针指向的对象是否存在 */
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const {
    auto ret = wptr.lock(); // 判断容器是否还在
    if (!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }

    return ret;
}

/* 解引用指针 */
string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

/* 返回递增后的对象的引用 */
StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++ curr;
    return *this;
}

#endif