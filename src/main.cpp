// In the Name of God

#include <iostream>
#include <omp.h>
#include <fstream>

#include "manual.hpp"
#include "simulator.hpp"
#include "initializer.hpp"
#include "consense_protocol.hpp"

using namespace std;

void simple_consense_protocol_test()
{
    int number_of_tests = 2000;
    string file_name = "simple_consense_protocol_test.txt";
    double reward_value = 5;
    int coin_value_a = 10;
    int coin_value_b = 20;
    int number_of_blocks = 2000;

    Initializer init;
    vector< vector<Participant> > test_results = vector< vector<Participant> >(number_of_tests);

    #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        //  printf(">>>    thread: %d --Test: i = %d \n", omp_get_thread_num(), int(i));
        Simulator simulator(new ConsenseProtocol(), reward_value);
        simulator.add_participants(init.generate_two_participants(coin_value_a, coin_value_b));
        simulator.run(number_of_blocks);
        test_results[i] = simulator.get_participants();
    }
    double sum = 0;
    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value = test_results[i][0].get_totall_coins_value();
        cout << "Test " << i << " : " << value << " percent:" << value / 5030 << endl;
        sum += value;
    }
    cout << "Average: " << sum / number_of_tests << endl;

    // open file
    ofstream file;
    file.open(file_name);
    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value1 = test_results[i][0].get_totall_coins_value();
        double value2 = test_results[i][1].get_totall_coins_value();
        file << value1 << " " << value2 << endl;
    }
    file.close();
}

int main()
{
    simple_consense_protocol_test();


    // int number_of_participants = 10;
    // int number_of_blocks = 50;
    // int stake_duration = 3;
    // double reward_value = 10;
    // Initializer init;

    // double constant_reward_value = 10;
    // int time_period = 10;
    // Simulator simulator(new GeometricConsenseProtocol(time_period), constant_reward_value);

    // // Simulator simulator(new ConsenseProtocol(), reward_value);
    // // Simulator simulator(new ConsenseProtocol(), reward_value, stake_duration);

    // // Simulator simulator(new ZahraConsenseProtocol(), reward_value);
    // // Simulator simulator(new ZahraConsenseProtocol(), reward_value, stake_duration);


    // // simulator.add_participants(init.generate_random_participants(number_of_participants));
    // simulator.add_participants(init.generate_simple_participants(number_of_participants));
    // simulator.run(number_of_blocks);
    return 0;
}