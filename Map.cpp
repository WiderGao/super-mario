#include "Map.h"
#include <algorithm>

void Map::init(BaseObject* h)
{
    hero = h;

    loadimage(&background, _T("assets\\images\\map1.png"));
    _width = background.getwidth();
    _height = background.getheight();
    int unit_length = 36;
    //��Ԫ��Ϊ35*35�ķ���ȫ��ͼ����228����Ԫ������14����Ԫ
    //ע�������Ǵ�0��ʼ��
    //������
    rocket.push_back(Rocket(0 * unit_length, 10 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(0 * unit_length, 11 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(2 * unit_length, 10 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(2 * unit_length, 11 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));

    //�̵�ײ��ʯ
    rocket.push_back(Rocket(-1 * unit_length, 0 * unit_length, 1 * unit_length, 14 * unit_length));
    rocket.push_back(Rocket(228 * unit_length, 0 * unit_length, 1 * unit_length, 14 * unit_length));
    rocket.push_back(Rocket(0 * unit_length, 12 * unit_length, 69 * unit_length, 2 * unit_length));
    rocket.push_back(Rocket(71 * unit_length, 12 * unit_length, 15 * unit_length, 2 * unit_length));
    rocket.push_back(Rocket(89 * unit_length, 12 * unit_length, 64 * unit_length, 2 * unit_length));
    rocket.push_back(Rocket(155 * unit_length, 12 * unit_length, 73 * unit_length, 2 * unit_length));
    rocket.push_back(Rocket(0 * unit_length, 14 * unit_length, 227 * unit_length, 1 * unit_length));
    
    //�̵�Ĭ��ɽ��
    for(int i=0;i<4;i++)
        rocket.push_back(Rocket((134+i) * unit_length, (11-i) * unit_length, 1 * unit_length, (i+1) * unit_length));
    for(int i = 0; i < 4; i++)
        rocket.push_back(Rocket((140 + i) * unit_length, (8 + i) * unit_length, 1 * unit_length, (4 - i) * unit_length));
    for(int i = 0; i < 4; i++)
        rocket.push_back(Rocket((148 + i) * unit_length, (11 - i) * unit_length, (5-i) * unit_length, 1 * unit_length));
    for(int i = 0; i < 4; i++)
        rocket.push_back(Rocket((155 + i) * unit_length, (8 + i) * unit_length, 1 * unit_length, (4 - i) * unit_length));
    for(int i = 0; i < 8; i++)
        rocket.push_back(Rocket((181 + i) * unit_length, (11 - i) * unit_length, (9 - i) * unit_length, 1 * unit_length));
    rocket.push_back(Rocket(212 * unit_length, 11 * unit_length, 1 * unit_length, 1 * unit_length));

    //�̵�Ư����ʯ
    rocket.push_back(Rocket(16 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 5; i++)
        rocket.push_back(Rocket((20 + i) * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(22 * unit_length, 4 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 3; i++)
        rocket.push_back(Rocket((77 + i) * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 8; i++)
        rocket.push_back(Rocket((80 + i) * unit_length, 4 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 4; i++)
        rocket.push_back(Rocket((91 + i) * unit_length, 4 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(94 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(100 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(106 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(109 * unit_length, 4 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(109 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(112 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    rocket.push_back(Rocket(117 * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 3; i++)
        rocket.push_back(Rocket((120 + i) * unit_length, 4 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 4; i++)
        rocket.push_back(Rocket((127 + i) * unit_length, 4 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 2; i++)
        rocket.push_back(Rocket((128 + i) * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));
    for(int i = 0; i < 4; i++)
        rocket.push_back(Rocket((168 + i) * unit_length, 8 * unit_length, 1 * unit_length, 1 * unit_length, "rock1"));

    //rocket_sorted_by_left = rocket;
    //rocket_sorted_by_right = rocket;
    //sort(rocket_sorted_by_left.begin(), rocket_sorted_by_left.end(), [](Rocket &a,Rocket &b) {
    //    if(a.position.x() < b.position.x()) return true;
    //    if(a.position.x() == b.position.x() && a.position.y() < b.position.y()) return true;
    //    return false;
    //});
    //sort(rocket_sorted_by_right.begin(), rocket_sorted_by_right.end(), [](Rocket& a, Rocket& b) {
    //    if(a.position.x() + a.width() -1 > b.position.x() + b.width() - 1) return true;
    //    if(a.position.x() + a.width() - 1 == b.position.x() + b.width() - 1 && a.position.y() + a.height() -1 < b.position.y() + b.height() - 1) return true;
    //    return false;
    //});
    for(auto &i : rocket) i.init();

}

void Map::show(Vector offset)
{
    putimage(0 + static_cast<int>(offset.x()), 0 + static_cast<int>(offset.y()), &background);
    for(auto &i: rocket)
        if(i.type()!="rock0")
            i.show(offset);
}
int Map::width() {
    return _width;
}
int Map::height() {
    return _height;
}
void Map::update()
{
    check_crash();
}

bool Map::left_exist_object(BaseObject &t)
{
    for(auto& i : rocket)
        if(t.position.x() == i.position.x() + i.width() && t.position.y() == i.position.y())
            return true;
    return false;
}

bool Map::right_exist_object(BaseObject& t)
{
    for(auto& i : rocket)
        if(t.position.x() + t.width() == i.position.x() && t.position.y() == i.position.y())
            return true;
    return false;
}

void Map::check_crash()
{
    for(auto &i : rocket) {
        if(i.position.x() > hero->position.x() + hero->width() || i.position.x() + i.width() < hero->position.x()) 
            continue;
        hero->block_crash(i, left_exist_object(i), right_exist_object(i));
    }

    //vector<Rocket>:: reverse_iterator l;
    //vector<Rocket>::iterator r;
    //r = lower_bound(rocket_sorted_by_left.begin(), rocket_sorted_by_left.end(), *hero, [](BaseObject mid, BaseObject val) {
    //    return mid.position.x() < val.position.x() + val.width() -1;
    //});
    //l = upper_bound(rocket_sorted_by_right.rbegin(), rocket_sorted_by_right.rend(), *hero, [](BaseObject val, BaseObject mid) {
    //    return val.position.x() < mid.position.x() + mid.width() -1;
    //});
    //
    //static auto time_tick = steady_clock::now();
    //if((steady_clock::now() - time_tick) >= milliseconds(500)) {
    //    time_tick = steady_clock::now();
    //    for(vector<Rocket>::iterator i = l.base()--;  i!= rocket_sorted_by_right.end() ; i++) {
    //        if((*i).position.x() != (*l.base()--).position.x()) break;
    //        hero->block_crash(i);
    //        //cout << (*i).position.y() << endl;
    //    }
    //    for(auto  i = r; i != rocket_sorted_by_left.end(); i++) {
    //        if((*i).position.x() != (*r).position.x()) break;
    //        hero->block_crash(*i);
    //        //cout << (*i).position.y() << endl;
    //    }
    //    //cout << (*l.base()--).position.x() + (*l.base()--).width() - 1 << ' ' << (*(r)).position.x() << endl;
    //}

}
