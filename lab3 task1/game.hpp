#pragma once
#include "base.hpp"

template<class hero1, class hero2>
class game{
    game(const hero1& f, const hero2& s);

    int winner(); //-1 - game is still going, 0 - both died, 1- first hero won, 2 - second hero won

    void turn(int hit1_, int hit2_, int block1_, int block2_);

private:
    hero1 first_;
    hero2 second_;
};

template <class hero1, class hero2>
game<hero1, hero2>::game(const hero1& f, const hero2& s){
    first_ = f;
    second_ = s;
}

template <class hero1, class hero2>
int game<hero1, hero2>::winner(){
    if (first_.getHp != 0 && second_.getHp() != 0){
        return -1;
    }

    if (first_.getHp == 0 && second_.getHp() == 0){
        return 0;
    }

    if (first_.getHp != 0 && second_.getHp() == 0){
        return 1;
    }

    if (first_.getHp == 0 && second_.getHp() != 0){
        return 2;
    }
}

template <class hero1, class hero2>
void game<hero1, hero2>::turn(int hit1_, int hit2_, int block1_, int block2_){
    info diff1, diff2;
    info info1 = first_.getInfo(), info2 = second_.getInfo();

    if (first_.getStun() == 0){
        switch (hit1_) {
        case 1:
            if (block2_ != 1) diff2 = first_.upper(info2);
            break;
        case 2:
            if (block2_ != 2) diff2 = first_.middle(info2);
            break;
        case 3:
            if (block2_ != 3) diff2 = first_.lower(info2);
            break;
        }
    }

    if (second_.getStun() == 0){
        switch (hit2_) {
        case 1:
            if (block1_ != 1) diff1 = second_.upper(info1);
            break;
        case 2:
            if (block1_ != 2) diff1 = second_.middle(info1);
            break;
        case 3:
            if (block1_ != 3) diff1 = second_.lower(info1);
            break;
        }
    }

    first_.getHit(diff1);
    second_.getHit(diff2);
}
