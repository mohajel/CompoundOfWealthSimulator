// In the Name of God

#include "coin.hpp"

#include <iostream>

using namespace std;

Coin::Coin(double value, int block_created)
{
    this->value = value;
    this->block_created = block_created;
}

Coin::~Coin()
{
}

double Coin::get_value()
{
    return this->value;
}

int Coin::get_block_created()
{
    return this->block_created;
}

