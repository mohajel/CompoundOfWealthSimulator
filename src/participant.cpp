// In the Name of God

#include "participant.hpp"

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
