// In the Name of God

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <iomanip>
#include <fstream>


#include "initializer.hpp"
#include "manual.hpp"
#include "participant.hpp"
#include "coin.hpp"
#include "data_analyzer.hpp"


using namespace std;

DataAnalyzer::DataAnalyzer()
{
    // cout << "DataAnalyzer Constructor" << endl;
}

DataAnalyzer::~DataAnalyzer()
{
    // cout << "DataAnalyzer Destructor" << endl;
}

double DataAnalyzer::calculate_gini_coefficient(vector<Participant> &participants)
{
    double result = 0;
    int n = participants.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n ; j++)
            result += abs(participants[i].get_totall_coins_value() - participants[j].get_totall_coins_value());
    return result / (2 * n);
}

void DataAnalyzer::write_to_file(vector<Participant> &participants, string file_name)
{
    ofstream output_file(file_name);
    for (int i = 0; i < participants.size(); i++)
        output_file << participants[i].get_totall_coins_value() << endl;
    output_file.close();
}

// void DataAnalyzer::analyze
