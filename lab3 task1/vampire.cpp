#pragma once
#include "vampire.hpp"

vampire::vampire(){
    setHp(100);
    setStun(0);
}

info vampire::upper(info opponent){
    return info(15);
}

info vampire::middle(info opponent){
    int damage = (8 * (100 - getHp()))/10;
    return info(damage);
}

info vampire::lower(info opponent){
    int damage = (5 * getHp())/10;
    return info(damage);
}
