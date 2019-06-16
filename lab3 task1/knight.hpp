#pragma once
#include "base.hpp"

class knight : public base{
public:
    knight();

    info upper(info opponent);
    info middle(info opponent);
    info lower(info opponent);

    void getHit(info diff);

private:
    int shield_;
};

