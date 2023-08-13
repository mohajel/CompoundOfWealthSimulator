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

void Stake::print_status()
{
    // cout << "Stake status:" << endl;

    // Bug in here : owner is null
    // if (this->owner == NULL)
    //     cout << "Owner: NULL" << endl;
    // else
    //     cout << "Owner: " << this->owner->get_name() << endl;
    cout << "Owner: " << this->owner->get_name() << endl;

    cout << "---Coins: " << endl;
    for (size_t i = 0; i < coins.size(); i++)
    {
        cout << "------Coin " << i << ":" << endl;
        cout << "------Value: " << coins[i].get_value() << endl;
        cout << "------Block created: " << coins[i].get_block_created() << endl;
    }
}


bool Stake::is_empty()
{
    if (this->coins.size() == 0)
        return true;
    for (size_t i = 0; i < coins.size(); i++)
        if (coins[i].get_value() != 0)
            return false;
    return true;
}

bool Stake::update_stake()
{
    this->blocks_left--;
    if (this->blocks_left != 0)
        return true;
    
    this->owner->add_coin(this->coins);
    return false;
}
