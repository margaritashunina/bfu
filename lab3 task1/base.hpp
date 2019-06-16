#pragma once
#include <iostream>
#include <functional>
#include <vector>

struct info{
    int hp, stun;

    info(int h = 0, int s = 0):
        hp(h), stun(s){}
};

class base{
public:
    base(int hp = 0):
        hp_(hp){}

    void setHp(int hp);
    void setStun(int s);
    void getDamage(int dx);

    info getInfo();
    int getStun();
    int getHp();

    virtual info upper(info opponent);
    virtual info middle(info opponent);
    virtual info lower(info opponent);

    virtual void getHit(info diff);

private:
    int hp_, stun_;
};
