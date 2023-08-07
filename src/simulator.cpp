// In the Name of God

#include <iostream>
#include <vector>

#include "simulator.hpp"
#include "participant.hpp"


using namespace std;

Simulator::Simulator(/* args */)
{
}

Simulator::~Simulator()
{
}

void Simulator::run()
{
    cout << "Hello World!" << endl;
    
}

void Simulator::add_participants(vector<Participant> participants)
{
    this->participants = participants;

}

void Simulator::add_participants(Participant participant)
{
    this->participants.push_back(participant);
}
