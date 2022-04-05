#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include <string>
#include "MyDeclare.h"

/* Window_mgr�� */
class Window_mgr {
    /* ˽�� */
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};   // ���ڰ�������Ļ
    
    /* ���� */
    public:
        typedef std::vector<Screen>::size_type ScreenIndex; // ��Ļ���
        void clear(ScreenIndex i) {
            // ��ָ����ŵ���Ļ�ÿ�
            Screen& s = screens[i];
            s.contents = std::string(s.height * s.width, ' ');
        }

};

#endif
