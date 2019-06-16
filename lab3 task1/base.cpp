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
