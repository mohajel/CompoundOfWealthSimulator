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
    int number_of_tests = 5000;
    string file_name = "./data/simple-demo.txt";
    double reward_value = 40;
    int coin_value_a = 10;
    int coin_value_b = 20;
    int number_of_blocks = 1000;

    Initializer init;
    vector<vector<Participant>> test_results = vector<vector<Participant>>(number_of_tests);

    // open file
    ofstream file;
    file.open(file_name);

    #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        //  printf(">>>    thread: %d --Test: i = %d \n", omp_get_thread_num(), int(i));
        Simulator simulator(new ConsenseProtocol(), reward_value);
        simulator.add_participants(init.generate_two_participants(coin_value_b, coin_value_a));
        simulator.run(number_of_blocks);
        test_results[i] = simulator.get_participants();
    }
    double sum = 0;
    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value = test_results[i][0].get_totall_coins_value();
        // cout << "Test " << i << " : " << value << " percent:" << value / 5030 << endl;
        sum += value;
    }
    cout << "Average: " << sum / number_of_tests << endl;


    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value1 = test_results[i][0].get_totall_coins_value();
        double value2 = test_results[i][1].get_totall_coins_value();
        file << value1 << " " << value2 << endl;
    }
    file.close();
}

void simple_ten()
{
    // int number_of_tests = 5000;
    int number_of_tests = 1;

    int number_of_participants = 10;
    string file_name = "./data/simple_ten.txt";
    double reward_value = 1;
    // int number_of_blocks = 1000;
    int number_of_blocks = 10;

    Initializer init;
    vector<vector<Participant>> test_results = vector<vector<Participant>>(number_of_tests);

    // open file
    ofstream file;
    file.open(file_name);

    // #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        //  printf(">>>    thread: %d --Test: i = %d \n", omp_get_thread_num(), int(i));
        Simulator simulator(new ConsenseProtocol(), reward_value);
        simulator.add_participants(init.generate_simple_participants(number_of_participants));
        simulator.run(number_of_blocks);
        test_results[i] = simulator.get_participants();
    }
    double sum = 0;
    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value = test_results[i][0].get_totall_coins_value();
        // cout << "Test " << i << " : " << value << " percent:" << value / 5030 << endl;
        sum += value;
    }
    cout << "Average: " << sum / number_of_tests << endl;


    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value1 = test_results[i][0].get_totall_coins_value();
        double value2 = test_results[i][1].get_totall_coins_value();
        file << value1 << " " << value2 << endl;
    }
    file.close();
}

void zahra_consense_protocol_test()
{
    int number_of_tests = 5000;
    string file_name = "data/zahra.txt";
    double reward_value = 40;
    int coin_value_a = 10;
    int coin_value_b = 20;
    int number_of_blocks = 1000;

    Initializer init;
    vector<vector<Participant>> test_results = vector<vector<Participant>>(number_of_tests);

    #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        //  printf(">>>    thread: %d --Test: i = %d \n", omp_get_thread_num(), int(i));
        Simulator simulator(new ZahraConsenseProtocol(), reward_value);
        simulator.add_participants(init.generate_two_participants(coin_value_b, coin_value_a));
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

void geometric_consense_protocol_test()
{
    int number_of_tests = 5000;
    string file_name = "data/geometric-1.txt";
    double constant_reward_value = 40;
    int coin_value_a = 10;
    int coin_value_b = 20;
    int number_of_blocks = 1000;
    int time_period = 1000;

    Initializer init;
    vector<vector<Participant>> test_results = vector<vector<Participant>>(number_of_tests);

    #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        //  printf(">>>    thread: %d --Test: i = %d \n", omp_get_thread_num(), int(i));
        Simulator simulator(new GeometricConsenseProtocol(time_period), constant_reward_value);
        simulator.add_participants(init.generate_two_participants(coin_value_b, coin_value_a));
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

void pow_consence_protocol_test()
{
    int number_of_tests = 5000;
    // int number_of_tests = 1;

    string file_name = "./data/pow.txt";
    double reward_value = 40;
    int coin_value_a = 10;
    int coin_value_b = 20;

    int number_of_blocks = 1000;
    // int number_of_blocks = 10;

    Initializer init;
    vector<vector<Participant>> test_results = vector<vector<Participant>>(number_of_tests);

    // open file
    ofstream file;
    file.open(file_name);

    #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        Simulator simulator(new ConsenseProtocol(), reward_value);
        simulator.add_participants(init.generate_two_pow_participants(coin_value_b, coin_value_a));
        simulator.run(number_of_blocks);
        test_results[i] = simulator.get_participants();
    }
    double sum = 0;
    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value = test_results[i][0].get_totall_coins_value();
        sum += value;
    }
    cout << "Average: " << sum / number_of_tests << endl;


    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value1 = test_results[i][0].get_totall_coins_value();
        double value2 = test_results[i][1].get_totall_coins_value();
        file << value1 << " " << value2 << endl;
    }
    file.close();
}


void time_variant_consense_protocol_test()
{
    int number_of_tests = 5000;
    // int number_of_tests = 1;
    string file_name = "./data/time_variant.txt";
    double reward_value = 40;
    int coin_value_a = 10;
    int coin_value_b = 20;
    int number_of_blocks = 1000;
    // int number_of_blocks = 10;

    Initializer init;
    vector<vector<Participant>> test_results = vector<vector<Participant>>(number_of_tests);

    // open file
    ofstream file;
    file.open(file_name);

    #pragma omp parallel for
    for (size_t i = 0; i < number_of_tests; i++)
    {
        //  printf(">>>    thread: %d --Test: i = %d \n", omp_get_thread_num(), int(i));
        Simulator simulator(new TimeVariantConsenseProtocol(), reward_value);
        simulator.add_participants(init.generate_two_participants(coin_value_b, coin_value_a));
        simulator.run(number_of_blocks);
        test_results[i] = simulator.get_participants();
    }
    double sum = 0;
    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value = test_results[i][0].get_totall_coins_value();
        // cout << "Test " << i << " : " << value << " percent:" << value / 5030 << endl;
        sum += value;
    }
    cout << "Average: " << sum / number_of_tests << endl;


    for (size_t i = 0; i < test_results.size(); i++)
    {
        double value1 = test_results[i][0].get_totall_coins_value();
        double value2 = test_results[i][1].get_totall_coins_value();
        file << value1 << " " << value2 << endl;
    }
    file.close();
}

void two_people_test()
{
    simple_consense_protocol_test();
    // pow_consence_protocol_test();
    // zahra_consense_protocol_test();
    // geometric_consense_protocol_test();
    // time_variant_consense_protocol_test();
}

void ten_people_test()
{
    simple_ten();

}

int main()
{
    simple_consense_protocol_test();

    // ten_people_test();



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