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

double get_random_number(double min, double max) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    double result = dis(gen);
    // cout << "random number: " << result << endl;                                 
    return result;
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
    double max_coin_value = this->get_total_stakes_value(stakes);

    // find floor of max_coin_value
    int max_value = floor(max_coin_value);
    // cout << "max value: " << max_value << endl;

    // find random number between 0 and max_coin_value using rand function
    double chosen_coin = get_random_number(0, max_coin_value);
    // cout << "chosen coin: " << chosen_coin << endl;

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
    cout << "Error in ConsenseProtocol::find_winner_stake" << endl;
    exit(EXIT_FAILURE);
    return stakes[stakes.size() - 1];
}

void ConsenseProtocol::distribute_rewards(Stake &winner_stake, std::vector<Stake> &stakes, double reward_value, int last_block)
{
    winner_stake.owner->add_coin(Coin(reward_value, last_block));
}

double ConsenseProtocol::get_total_stakes_value(std::vector<Stake> &stakes)
{
    double result = 0;
    for (size_t i = 0; i < stakes.size(); i++)
    {
        vector<Coin> coins = stakes[i].coins;
        for (size_t j = 0; j < coins.size(); j++)
            result += coins[j].get_value();
    }
    return result;
}

double ConsenseProtocol::get_total_participants_value(std::vector<Participant> &participants)
{
    double result = 0;
    for (size_t i = 0; i < participants.size(); i++)
    {
        result += participants[i].get_totall_coins_value();
    }
    return result;
}


ZahraConsenseProtocol::ZahraConsenseProtocol(/* args */)
{
}

ZahraConsenseProtocol::~ZahraConsenseProtocol()
{
}

void ZahraConsenseProtocol::distribute_rewards(Stake &winner_stake, std::vector<Stake> &stakes, double reward_value, int last_block)
{
    cout << "Zahra distribute_rewards" << endl;
    // get all coins from all stakes
    double max_coin_value = get_total_stakes_value(stakes);

    // find floor of max_coin_value
    int max_value = floor(max_coin_value);

    winner_stake.owner->add_coin(Coin(reward_value * 0.5, last_block));

    for (size_t i = 0; i < stakes.size(); i++)
    {
        double stakes_totall_coin = stakes[i].get_totall_coins_value();
        stakes[i].owner->add_coin(Coin(reward_value * 0.5 * stakes_totall_coin / max_coin_value, last_block));
    }
}

GeometricConsenseProtocol::GeometricConsenseProtocol(int time_period)
    :
    time_period(time_period)
{
}

void GeometricConsenseProtocol::distribute_rewards(Stake &winner_stake, std::vector<Stake> &stakes, double reward_value, int last_block_number)
{
    double reward = calculate_reward(last_block_number, reward_value);
    ConsenseProtocol::distribute_rewards(winner_stake, stakes, reward, last_block_number);
}

double GeometricConsenseProtocol::calculate_reward(int block_number, double constant_block_reward)
{
    double r = constant_block_reward * this->time_period;
    int n = ((block_number - 1) % this->time_period) + 1;

    double t = this->time_period;
    double reward = pow(1 + r, n / t) - pow(1 + r, (n - 1) / t);

    // print all for debug
    // cout << "-- block_number = " << block_number << endl;
    // cout << "t = " << t << endl;
    // cout << "r = " << r << endl;
    // cout << "n = " << n << endl;
    // cout << "reward = " << reward << endl;

    return reward;
}
