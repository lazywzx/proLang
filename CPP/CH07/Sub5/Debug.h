#ifndef DEBUG_H
#define DEBUG_H

/* Debug�� */
class Debug {
    /* ˽�� */
    private:
        /* ���ݳ�Ա */
        bool hw;    // Ӳ������
        bool io;    // IO����
        bool other; // ��������
    
    /* ���� */
    public:
        /* ��Ա���� */
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

        /* ���캯�� */
        constexpr Debug(bool b = true):
            hw(b), io(b), other(b) {}
        constexpr Debug(bool h, bool i, bool o):
            hw(h), io(i), other(o) {}
        
};

#endif