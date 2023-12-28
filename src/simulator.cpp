// In the Name of God

#include <iostream>
#include <vector>

#include "simulator.hpp"
#include "participant.hpp"
#include "coin.hpp"
#include "consense_protocol.hpp"
#include "data_analyzer.hpp"


using namespace std;

Simulator::Simulator(ConsenseProtocol* cp, double rw, int stake_duration) 
    : 
    last_block_number(0),
    consense_protocol(cp),
    reward_value(rw),
    stake_duration(stake_duration)
{
}

Simulator::~Simulator()
{
    delete consense_protocol;
}

void Simulator::run(int number_of_blocks)
{
    // DataAnalyzer* data_analyzer = new DataAnalyzer();

    // data_analyzer->write_to_file(participants, "initial_data.txt");
    // cout << "Initial Gini Coefficient: " << data_analyzer->calculate_gini_coefficient(participants) << endl;

    cout << "Simulator is running" << endl;
    // print_participants_status();

    for (int i = 0; i < number_of_blocks; i++)
    {
        last_block_number ++;
        // cout << "Block : " << last_block_number << endl;

        get_stakes_from_participants();
        Stake winner_stake = consense_protocol->find_winner_stake(stakes);
        // cout << "Winner Participant: " << winner_stake.owner->get_name() << endl;
        consense_protocol->distribute_rewards(winner_stake, stakes, reward_value, last_block_number);
        this->update_stakes();

        // this->print_stakes_status();
        // print_participants_status();
    }
    while (stakes.size() > 0)
    {
        last_block_number ++;
        // cout << "Block : (some stakes remain)" << last_block_number << endl;
        this->update_stakes();
        // print_participants_status();
    }
    // cout << "All participunts coins sum :" << consense_protocol->get_total_participants_value(participants) << endl;
    // data_analyzer->write_to_file(participants, "final_data.txt");
    // cout << "Final Gini Coefficient: " << data_analyzer->calculate_gini_coefficient(participants) << endl;
    // delete data_analyzer;
    print_participants_status();
}

void Simulator::print_participants_status()
{
    cout << "Participants status:" << endl;
    for (size_t i = 0; i < participants.size(); i++)
    {
        // cout << "Participant " << i << ":" << endl;
        participants[i].print_status();
    }
}

void Simulator::print_stakes_status()
{
    cout << "Stakes status in block : " << this->last_block_number << endl;

    if (stakes.size() == 0)
    {
        cout << "No stakes EMPTY" << endl;
        return;
    }
    for (size_t i = 0; i < stakes.size(); i++)
    {
        cout << "Stake " << i << ":" << endl;
        stakes[i].print_status();
    }
}

void Simulator::get_stakes_from_participants()
{
    for (size_t i = 0; i < participants.size(); i++)
    {
        stakes.push_back(participants[i].generate_stake(this->stake_duration));
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

vector<Participant> Simulator::get_participants()
{
    return this->participants;
}

void Simulator::update_stakes()
{
    // cout << "Stakes size before update: " << stakes.size() << endl;
    for (long long int i = stakes.size() -1 ; i >= 0; i--)
    {
        bool stake_remained = stakes[i].update_stake();
        if (stake_remained == false)
            stakes.erase(stakes.begin() + i);
    }
    // cout << "Stakes size after update: " << stakes.size() << endl;
}
