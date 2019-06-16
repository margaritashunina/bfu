#pragma once
#include "base.hpp"


class vampire : public base{
public:
    vampire();

    info upper(info opponent) override;
    info middle(info opponent) override;
    info lower(info opponent) override;
};
