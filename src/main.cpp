// In the Name of God

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "manual.hpp"
#include "simulator.hpp"
#include "initializer.hpp"
#include "consense_protocol.hpp"

using namespace std;

int main()
{
    int number_of_participants = 10;
    int number_of_blocks = 10;
    Initializer init;
    Simulator simulator(new ZahraConsenseProtocol());
    // Simulator simulator(new ConsenseProtocol());

    // simulator.add_participants(init.generate_random_participants(number_of_participants));
    simulator.add_participants(init.generate_simple_participants(number_of_participants));
    simulator.run(number_of_blocks);
    return 0;
}