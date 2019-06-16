#pragma once
#include "base.hpp"

class fairy : public base{
public:
    fairy();

    info upper(info opponent) override;
    info middle(info opponent) override;
    info lower(info opponent) override;

private:
    int poison_;
};
