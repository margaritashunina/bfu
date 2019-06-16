#pragma once
#include "base.hpp"


class vampire : public base{
    vampire();

    info upper(info opponent);
    info middle(info opponent);
    info lower(info opponent);

    void getHit(info diff);
};
