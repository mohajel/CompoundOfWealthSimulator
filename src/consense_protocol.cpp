// In the Name of God

#include <iostream>
#include <vector>
#include <random>


#include "consense_protocol.hpp"
#include "manual.hpp"
#include "participant.hpp"
#include "coin.hpp"


using namespace std;

ConsenseProtocol::ConsenseProtocol()
{
    
}

ConsenseProtocol::~ConsenseProtocol()
{
}

Participant ConsenseProtocol::find_winner_participant(vector<Participant> &participants)
{
    Participant winner_participant = participants[0];
    // TODO: implement this function


    // int max_coin_value = 0;
    // for (size_t i = 0; i < participants.size(); i++)
    // {
    // }
    return winner_participant;
}