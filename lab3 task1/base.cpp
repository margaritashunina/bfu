#pragma once
#include "base.hpp"

void base::setHp(int hp){
    hp_ = hp;
}

void base::setStun(int s){
    stun_ = s;
}

void base::getDamage(int dx){
    hp_ -= dx;
}

info base::getInfo(){
    return info(hp_, stun_);
}

int base::getStun(){
    return stun_;
}
int base::getHp(){
    return hp_;
}

info base::upper(info opponent){
    return info();
}

info base::middle(info opponent){
    return info();
}

info base::lower(info opponent){
    return info();
}

void base::getHit(info diff){
    getDamage(diff.hp);
    if (diff.stun != 0) setStun(diff.stun);
}
