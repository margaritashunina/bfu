#pragma once
#include "base.hpp"

class fairy : public base{
public:
    fairy();

    info upper(info opponent);
    info middle(info opponent);
    info lower(info opponent);

    void getHit(info diff);

private:
    int poison_;
};
