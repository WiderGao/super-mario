#pragma once
#include "Global.h"

//ʱ�������RATE=1000 ms : ����ˢ�¼��������ÿ������ˢ�µĻ���
#define RATE 100.0

//�������ٶ�
#define G 25

//MovableObject�����п��ƶ�������Ļ���
class MovableObject
{
    protected:
        double x;
        double y;
        double vx;
        double vy;
        double ax;
        double ay;
        bool is_running;
        bool is_jumping;
        int direction;
    public:
        MovableObject(int, int, bool, bool, int);
        int getX();
        int getY();
        void setX(double);
        void setY(double);
        void run(int, double);
        void jump();
        void still();
        void update();
};


inline MovableObject::MovableObject(int dx, int dy, bool run = 0, bool jump = 0, int drt = RIGHT):
    x(dx), y(dy), vx(0), vy(0), ax(0),ay(G/RATE),is_running(run), is_jumping(jump), direction(drt) {};

//ʵ����������������X
inline int MovableObject::getX()
{
    return round(x);
}

//ʵ����������������Y
inline int MovableObject::getY()
{
    return round(y);
}

//����X
inline void MovableObject::setX(double dx)
{
    x = dx;
}

//����Y
inline void MovableObject::setY(double dy)
{
    y = dy;
}

//��������״̬�������ƶ���drt������speed���ٶȣ���λpx/s��
inline void MovableObject::run(int drt, double speed = 250)
{
    if(drt == LEFT) {
        vx=0-speed/RATE;
    }
    if(drt == RIGHT) {
        vx=speed/RATE;
    }
    direction = drt;

    if(is_jumping)
        is_running = 0;
    else
        is_running = 1;
}

//������Ծ״̬���������ϵĳ��ٶ�
inline void MovableObject::jump()
{
    vy = 0-500.0/RATE;
    is_jumping = 1;
}

//���뾲ֹ״̬
inline void MovableObject::still()
{
    vx = 0;
    is_running = is_jumping = 0;
}

//����ʵʱ����
inline void MovableObject::update()
{
    static clock_t last = clock();//��ʱ��
    static clock_t now = clock();//��ʱ��
    //����ʹ��C++11�����chrono������п��о�
    //����ʱ����Ŀ���Ǿ�ȷ�����ٶȺ�λ��
    if((now=clock()) - last >= 10) {
        last = now; 
        x += vx;
        y += vy;
        vx += ax;
        vy += ay;
        //��ʵ�й�ʽ���Ը���ȷ����
        //������΢�־�ȷ��Ҳ���ԣ����Ҽ�
    }
}
