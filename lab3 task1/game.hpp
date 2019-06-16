#pragma once
#include "base.hpp"

class game{
    game(base* f, base* s);

    int winner(); //-1 - game is still going, 0 - both died, 1- first hero won, 2 - second hero won

    void turn(int hit1_, int hit2_, int block1_, int block2_);

private:
    base* first_;
    base* second_;
};

game::game(base* f, base* s){
    first_ = f;
    second_ = s;
}

int game::winner(){
    if (first_->getHp() != 0 && second_->getHp() != 0){
        return -1;
    }

    if (first_->getHp() == 0 && second_->getHp() == 0){
        return 0;
    }

    if (first_->getHp() != 0 && second_->getHp() == 0){
        return 1;
    }

    if (first_->getHp() == 0 && second_->getHp() != 0){
        return 2;
    }
}

void game::turn(int hit1_, int hit2_, int block1_, int block2_){
    info diff1, diff2;
    info info1 = first_->getInfo(), info2 = second_->getInfo();

    if (first_->getStun() == 0){
        switch (hit1_) {
        case 1:
            if (block2_ != 1) diff2 = first_->upper(info2);
            break;
        case 2:
            if (block2_ != 2) diff2 = first_->middle(info2);
            break;
        case 3:
            if (block2_ != 3) diff2 = first_->lower(info2);
            break;
        }
    }

    if (second_->getStun() == 0){
        switch (hit2_) {
        case 1:
            if (block1_ != 1) diff1 = second_->upper(info2);
            break;
        case 2:
            if (block1_ != 2) diff1 = second_->middle(info2);
            break;
        case 3:
            if (block1_ != 3) diff1 = second_->lower(info2);
            break;
        }
    }

    first_->getHit(diff1);
    second_->getHit(diff2);
}
