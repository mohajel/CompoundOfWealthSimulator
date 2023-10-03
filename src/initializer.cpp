// In the Name of God

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <iomanip>

#include "initializer.hpp"
#include "manual.hpp"
#include "participant.hpp"
#include "coin.hpp"

using namespace std;

Initializer::Initializer()
{
}

Initializer::~Initializer()
{
}

vector<Participant> Initializer::generate_random_participants(int number_of_participants)
{
    vector<Participant> participants;
    for (size_t i = 0; i < number_of_participants; i++)
        participants.push_back(this->get_random_participant(to_string(i)));
    return participants;
}

Participant Initializer::get_random_participant(string name)
{
    Participant participant(name);
    participant.add_coin(this->get_random_coin(100));
    return participant;
}

Participant Initializer::get_participant(string name, double coin_value)
{
    Participant participant(name);
    participant.add_coin(Coin(coin_value, 1));
    return participant;
}

Coin Initializer::get_random_coin(int interval)
{
    // create random number between 0 and interval
    int coin_value = rand() % interval;
    const int initial_block = 1;

    return Coin(coin_value, initial_block);
}

vector<Participant> Initializer::generate_simple_participants(int number_of_participants)
{
    vector<Participant> participants;
    double totall_coins = (1 + number_of_participants) * number_of_participants / 2;
    // TODO: ....

    for (size_t i = 1; i <= number_of_participants; i++)
    {
        participants.push_back(this->get_participant(to_string(i), i));
        // participants.push_back(this->get_participant(to_string(i), i + 0.2));
    }
    return participants;
}

vector<Participant> Initializer::generate_two_participants(int first_participant_coins_value,
                                                           int second_participant_coins_value)
{
    vector<Participant> participants;
    participants.push_back(this->get_participant("1", first_participant_coins_value));
    participants.push_back(this->get_participant("2", second_participant_coins_value));
    return participants;
}
