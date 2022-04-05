#ifndef SCREEN_H
#define SCREEN_H

#include <ostream>
#include <string>
#include "MyDeclare.h"

/* Screen类 */
class Screen {
    /* 友元声明 */
    friend void Window_mgr::clear(ScreenIndex); // 清空指定编号的屏幕

    /* 公有 */
    public:
        /* 类型成员 */
        typedef std::string::size_type pos;

        /* 构造函数 */
        Screen() = default;
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

        /* 成员函数 */
        char get() const {
            // 获取当前光标处字符
            ++ access_ctr;  // 追踪该函数被调用的次数
            return contents[cursor];
        }

        char get(pos ht, pos wd) const {
            // 获取指定坐标处字符
            return contents[ht * width + wd];
        }

        Screen& move(pos r, pos c) {
            // 将光标移动到指定坐标
            cursor = r * width + c;
            return *this;
        }

        Screen& set(char c) {
            // 设定当前光标处的字符
            contents[cursor] = c;
            return *this;
        }

        Screen& set(pos ht, pos wd, char c) {
            // 设定指定光标处的字符
            contents[ht * width + wd] = c;
            return *this;
        }

        Screen& display(std::ostream& os) {
            // 显示屏幕内容
            // 非常量对象调用，返回普通引用
            do_display(os);
            return *this;
        }

        const Screen& display(std::ostream& os) const {
            // 显示屏幕内容
            // 常量对象调用，返回常量引用
            do_display(os);
            return *this;
        }

    /* 私有 */
    private:
        /* 类成员 */
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents = "";
        // 可变数据成员
        mutable size_t access_ctr = 0;  // 追踪某成员函数被调用次数

        /* 成员函数 */
        void do_display(std::ostream& os) const {
            os << contents;
        }
};

#endif
