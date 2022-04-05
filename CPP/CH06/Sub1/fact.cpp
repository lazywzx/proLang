#include "Chapter6.hpp"

// Çó½×³Ë
int fact2(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val --;
    }

    return ret;
}
