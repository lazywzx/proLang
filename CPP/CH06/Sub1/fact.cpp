#include "Chapter6.hpp"

// ��׳�
int fact2(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val --;
    }

    return ret;
}
