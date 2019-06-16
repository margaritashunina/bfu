#pragma once
#include "knight.hpp"

knight::knight(){
    setHp(150);
    setStun(0);
    shield_ = 50;
}

info knight::upper(info opponent){
    shield_ = std::min(90, shield_ + 10);
    return info();
}
info knight::middle(info opponent){
    info tmp(shield_);
    shield_ = std::max(0, shield_ - 10);
    return tmp;
}
info knight::lower(info opponent){
    getDamage(50);
    shield_ = 90;
    return info();
}

void knight::getHit(info diff){
    int blockedDamage = (diff.hp * shield_)/100;
    getDamage(diff.hp - blockedDamage);
    if (diff.stun != 0) setStun(diff.stun);
}
