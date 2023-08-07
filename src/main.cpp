#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include <../include/manual.hpp>
#include <../include/simulator.hpp>

using namespace std;

int main()
{
    Simulator simulator;
    simulator.run();
    return 0;
}