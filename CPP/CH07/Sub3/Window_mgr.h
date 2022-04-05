#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include <string>
#include "MyDeclare.h"

/* Window_mgr类 */
class Window_mgr {
    /* 私有 */
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};   // 窗口包含的屏幕
    
    /* 公有 */
    public:
        typedef std::vector<Screen>::size_type ScreenIndex; // 屏幕编号
        void clear(ScreenIndex i) {
            // 将指定编号的屏幕置空
            Screen& s = screens[i];
            s.contents = std::string(s.height * s.width, ' ');
        }

};

#endif
