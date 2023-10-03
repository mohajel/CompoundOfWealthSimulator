// In the Name of God

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double constant_block_reward = 10;
    double t = 10;
    double r = constant_block_reward * t;
    double sum = 0;

    // sum += pow(1 + r, 0) - pow(1 + r, (0 - 1) / t);
    for (size_t n = 1; n <= t; n++)
    {
        double each_reward = pow(1 + r, n / t) - pow(1 + r, (n - 1) / t);
        cout << "n = " << n << "::  " << each_reward << endl;

        sum += each_reward;
    }

    cout << endl << sum;
    
    return 0;
}