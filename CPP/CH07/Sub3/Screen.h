#ifndef SCREEN_H
#define SCREEN_H

#include <ostream>
#include <string>
#include "MyDeclare.h"

/* Screen�� */
class Screen {
    /* ��Ԫ���� */
    friend void Window_mgr::clear(ScreenIndex); // ���ָ����ŵ���Ļ

    /* ���� */
    public:
        /* ���ͳ�Ա */
        typedef std::string::size_type pos;

        /* ���캯�� */
        Screen() = default;
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

        /* ��Ա���� */
        char get() const {
            // ��ȡ��ǰ��괦�ַ�
            ++ access_ctr;  // ׷�ٸú��������õĴ���
            return contents[cursor];
        }

        char get(pos ht, pos wd) const {
            // ��ȡָ�����괦�ַ�
            return contents[ht * width + wd];
        }

        Screen& move(pos r, pos c) {
            // ������ƶ���ָ������
            cursor = r * width + c;
            return *this;
        }

        Screen& set(char c) {
            // �趨��ǰ��괦���ַ�
            contents[cursor] = c;
            return *this;
        }

        Screen& set(pos ht, pos wd, char c) {
            // �趨ָ����괦���ַ�
            contents[ht * width + wd] = c;
            return *this;
        }

        Screen& display(std::ostream& os) {
            // ��ʾ��Ļ����
            // �ǳ���������ã�������ͨ����
            do_display(os);
            return *this;
        }

        const Screen& display(std::ostream& os) const {
            // ��ʾ��Ļ����
            // ����������ã����س�������
            do_display(os);
            return *this;
        }

    /* ˽�� */
    private:
        /* ���Ա */
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents = "";
        // �ɱ����ݳ�Ա
        mutable size_t access_ctr = 0;  // ׷��ĳ��Ա���������ô���

        /* ��Ա���� */
        void do_display(std::ostream& os) const {
            os << contents;
        }
};

#endif
