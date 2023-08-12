// In the Name of God

#include <iostream>
#include <vector>
#include <random>


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
        participants.push_back(this->get_random_participant());
    return participants;
}

Participant Initializer::get_random_participant()
{
    Participant participant;
    participant.add_coin(this->get_random_coin(100));
    return participant;
}


Participant Initializer::get_participant(int coin_value)
{
    Participant participant;
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
    for (size_t i = 1; i <= number_of_participants; i++)
        participants.push_back(this->get_participant(i));
    return participants;
}




