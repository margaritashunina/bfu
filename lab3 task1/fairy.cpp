#pragma once
#include "fairy.hpp"

fairy::fairy(){
    setHp(30);
    setStun(0);
    poison_ = 0;
}

info fairy::upper(info opponent){
    return info(0, 1);
}

info fairy::middle(info opponent){
    info tmp(2, 0);
    if (poison_ != 0){
        tmp.hp *= 10;
    }
    return tmp;
}

info fairy::lower(info opponent){
    poison_ = 10;
    return info();
}
