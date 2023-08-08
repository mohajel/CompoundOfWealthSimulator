// In the Name of God

#include <iostream>
#include <vector>

#include "participant.hpp"
#include "stake.hpp"
#include "coin.hpp"

using namespace std;

Stake::Stake(vector<Coin> coins, int blocks_left, Participant *owner)
{
    this->coins = coins;
    this->blocks_left = blocks_left;
    this->owner = owner;
}


Stake::~Stake()
{
}