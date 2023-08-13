// In the Name of God

#include "participant.hpp"
#include "stake.hpp"

#include <iostream>

using namespace std;

Participant::Participant(float latancy, bool is_participating)
{
    this->latancy = latancy;
    this->is_participating = is_participating;
}

Participant::~Participant()
{
}

void Participant::add_coin(Coin coin)
{
    this->coins.push_back(coin);
}

void Participant::add_coin(vector<Coin> coins)
{
    for (auto coin : coins)
        this->coins.push_back(coin);
}

Stake Participant::generate_stake()
{
    vector<Coin> coins;
    for (size_t i = 0; i < this->coins.size(); i++)
        coins.push_back(this->coins[i]);

    // clear coins
    this->coins.clear();
    
    return Stake(coins, 1, this);
}
