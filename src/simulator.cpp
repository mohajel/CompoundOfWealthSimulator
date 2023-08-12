// In the Name of God

#include <iostream>
#include <vector>

#include "simulator.hpp"
#include "participant.hpp"
#include "coin.hpp"
#include "consense_protocol.hpp"


using namespace std;

Simulator::Simulator(/* args */)
{
}

Simulator::~Simulator()
{
}

void Simulator::run(int number_of_blocks)
{
    cout << "Simulator is running" << endl;
    for (int i = 0; i < number_of_blocks; i++)
    {
        // get stakes from participants
        get_stakes_from_participants(); // Done


        //make this two 1 function in consemse protocol
        // find winner stake based on consense protocol
        // auto winner_stake = this->consense_protocol.find_winner_stake(stakes);

        // distribute rewards based on consense protocol


        // update / giveback stakes
    }   
}

void Simulator::get_stakes_from_participants()
{
    for (auto participant : participants)
    {
        stakes.push_back(participant.generate_stake());
    }
}

void Simulator::add_participants(vector<Participant> participants)
{
    this->participants = participants;

}

void Simulator::add_participants(Participant participant)
{
    this->participants.push_back(participant);
}
