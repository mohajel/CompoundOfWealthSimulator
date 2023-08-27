// In the Name of God

#include <iostream>

#include "participant.hpp"
#include "stake.hpp"
#include "manual.hpp"


using namespace std;

Participant::Participant(string name, float latancy, bool is_participating)
{
    this->name = name;
    this->latancy = latancy;
    this->is_participating = is_participating;
}

Participant::~Participant()
{
}

void Participant::print_status()
{
    // cout << "Participant status:" << endl;
    cout << "Participants Name: " << this->name << endl;
    // cout << "Latancy: " << this->latancy << endl;
    // cout << "Is participating: " << this->is_participating << endl;

    // totall coins:
    double total_coins = 0;
    for (size_t i = 0; i < coins.size(); i++)
        total_coins += coins[i].get_value();
    cout << " ---- Total coins: ---" << total_coins << endl;

    // cout << "---Coins: " << endl;
    // for (size_t i = 0; i < coins.size(); i++)
    // {
    //     cout << "------Coin " << i << ":" << endl;
    //     cout << "------Value: " << coins[i].get_value() << endl;
    //     cout << "------Block created: " << coins[i].get_block_created() << endl;
    // }
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
    
    return Stake(coins, STAKE_SIZE, this);
}

string Participant::get_name()
{
    return this->name;
}