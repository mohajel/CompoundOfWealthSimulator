// In the Name of God

#include <iostream>

#include "participant.hpp"
#include "stake.hpp"
#include "manual.hpp"


using namespace std;

Participant::Participant(string name, int type, float latancy, bool is_participating)
{
    this->name = name;
    this->latancy = latancy;
    this->is_participating = is_participating;
    this->type = type;
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

Stake Participant::generate_stake(int stake_duration)
{
    // messiest code ever! this part is for pow 1 is for pow
    if (this->type == 1)
        return this->generate_stake_initial_invest(stake_duration);
    
    vector<Coin> coins;
    for (size_t i = 0; i < this->coins.size(); i++)
        coins.push_back(this->coins[i]);

    // clear coins
    this->coins.clear();
    
    return Stake(coins, stake_duration, this);
}

string Participant::get_name()
{
    return this->name;
}

double Participant::get_totall_coins_value()
{
    double totall_coins_value = 0;
    for (size_t i = 0; i < this->coins.size(); i++)
        totall_coins_value += this->coins[i].get_value();
    return totall_coins_value;
}

Stake Participant::generate_stake_initial_invest(int stake_duration)
{
    // cout << "IN InitialInvestParticipant GENERATE STAKE" << endl;
    vector<Coin> coins;
    for (long long int i = 0; i < this->coins.size(); i++)
    {
        if (this->coins[i].get_block_created() == -1)
        {
            coins.push_back(this->coins[i]);
            this->coins.erase(this->coins.begin() + i);
            break;
        }
    }
    
    return Stake(coins, stake_duration, this);
}
