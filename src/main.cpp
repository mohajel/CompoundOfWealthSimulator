#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "manual.hpp"
#include "simulator.hpp"
#include "initializer.hpp"

using namespace std;

int main()
{
    int number_of_participants = 100;
    Simulator simulator;
    Initializer init;
    simulator.add_participants(init.generate_random_participants(number_of_participants));
    simulator.run();
    return 0;
}