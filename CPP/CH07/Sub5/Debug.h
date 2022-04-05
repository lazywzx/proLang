#ifndef DEBUG_H
#define DEBUG_H

/* Debug类 */
class Debug {
    /* 私有 */
    private:
        /* 数据成员 */
        bool hw;    // 硬件错误
        bool io;    // IO错误
        bool other; // 其他错误
    
    /* 共有 */
    public:
        /* 成员函数 */
        void set_hw(bool b) {
            hw = b;
        }
        void set_io(bool b) {
            io = b;
        }
        void set_other(bool b) {
            other = b;
        }

        constexpr bool any() {
            return hw || io || other;
        }

        /* 构造函数 */
        constexpr Debug(bool b = true):
            hw(b), io(b), other(b) {}
        constexpr Debug(bool h, bool i, bool o):
            hw(h), io(i), other(o) {}
        
};

#endif