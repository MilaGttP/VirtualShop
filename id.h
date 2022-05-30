#pragma once

#include <iostream>

class Id
{
private:
    static uint32_t id;
public:
    static uint32_t getId();
};