#pragma once
#include "base.hpp"

class knight : public base{
public:
    knight();

    info upper(info opponent) override;
    info middle(info opponent) override;
    info lower(info opponent) override;

    void getHit(info diff) override;

private:
    int shield_;
};

