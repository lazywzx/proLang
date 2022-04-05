#ifndef XY_H
#define XY_H

// 声明后，不完全类型，可定义指针或引用
class X;
class Y;

class X {
    Y* py;  // 指向Y类型的指针
}

class Y {
    X ox;   // X类型的对象
}

#endif
