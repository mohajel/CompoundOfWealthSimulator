// In the Name of God

#include <iostream>

#include "manual.hpp"
#include "simulator.hpp"
#include "initializer.hpp"
#include "consense_protocol.hpp"

using namespace std;

void simple_consense_protocol_test(int number_of_tests, string file_name)
{



    // Initializer init;
    // Simulator simulator(new ConsenseProtocol(), 10);
    // simulator.add_participants(init.generate_simple_participants(10));
    // simulator.run(number_of_tests);
    // simulator.print_results(file_name);
}

int main()
{
    int number_of_participants = 10;
    int number_of_blocks = 50;
    int stake_duration = 3;
    double reward_value = 10;
    Initializer init;

    double constant_reward_value = 10;
    int time_period = 10;
    Simulator simulator(new GeometricConsenseProtocol(time_period), constant_reward_value);

    // Simulator simulator(new ConsenseProtocol(), reward_value);
    // Simulator simulator(new ConsenseProtocol(), reward_value, stake_duration);

    // Simulator simulator(new ZahraConsenseProtocol(), reward_value);
    // Simulator simulator(new ZahraConsenseProtocol(), reward_value, stake_duration);


    // simulator.add_participants(init.generate_random_participants(number_of_participants));
    simulator.add_participants(init.generate_simple_participants(number_of_participants));
    simulator.run(number_of_blocks);
    return 0;
}