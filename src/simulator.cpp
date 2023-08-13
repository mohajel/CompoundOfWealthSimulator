// In the Name of God

#include <iostream>
#include <vector>

#include "simulator.hpp"
#include "participant.hpp"
#include "coin.hpp"
#include "consense_protocol.hpp"


using namespace std;

Simulator::Simulator(/* args */) 
    : 
    consense_protocol(),
    last_block_number(0)
{
}

Simulator::~Simulator()
{
}

void Simulator::run(int number_of_blocks)
{
    cout << "Simulator is running" << endl;

    double reward_value = 5;

    for (int i = 0; i < number_of_blocks; i++)
    {
        // get stakes from participants
        get_stakes_from_participants(); // Done


        //make this two 1 function in consemse protocol
        // find winner stake based on consense protocol
        Stake winner_stake = consense_protocol.find_winner_stake(stakes);

        // distribute rewards based on consense protocol
        consense_protocol.distribute_rewards(winner_stake, stakes, reward_value, last_block_number);


        // update / giveback stakes
        update_stakes();

        last_block_number ++;
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

void Simulator::update_stakes()
{
    // for (auto stake : stakes)
    // {
    //     stake.owner->update_stake(stake);
    // }
}
