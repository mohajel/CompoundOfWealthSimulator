// In the Name of God

#include <iostream>
#include <vector>
#include <random>

#include "consense_protocol.hpp"
#include "manual.hpp"
#include "participant.hpp"
#include "coin.hpp"
#include "stake.hpp"

using namespace std;

int get_random_number(int min, int max) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}


ConsenseProtocol::ConsenseProtocol(/* args */)
{
}

ConsenseProtocol::~ConsenseProtocol()
{
}

Stake ConsenseProtocol::find_winner_stake(std::vector<Stake> &stakes)
{
    // get all coins from all stakes
    double max_coin_value = 0;
    for (size_t i = 0; i < stakes.size(); i++)
    {
        vector<Coin> coins = stakes[i].coins;
        for (size_t j = 0; j < coins.size(); j++)
            max_coin_value += coins[j].get_value();
    }

    // find floor of max_coin_value
    int max_value = floor(max_coin_value);
    cout << "max value: " << max_value << endl;

    // find random number between 0 and max_coin_value using rand function
    int chosen_coin = get_random_number(0, max_value);
    cout << "chosen coin: " << chosen_coin << endl;

    for (size_t i = 0; i < stakes.size(); i++)
    {
        vector<Coin> coins = stakes[i].coins;
        for (size_t j = 0; j < coins.size(); j++)
        {
            chosen_coin = chosen_coin - coins[j].get_value();
            if (chosen_coin <= 0)
                return stakes[i];
        }
    }
    // never reachs here
    return stakes[stakes.size() - 1];
}

void ConsenseProtocol::distribute_rewards(Stake &winner_stake, std::vector<Stake> &stakes, double reward_value, int last_block)
{
    winner_stake.owner->add_coin(Coin(reward_value, last_block));
}
