#if !defined(__INITIALIZER__)
#define __INITIALIZER__

#include <string>
#include <vector>


#include "participant.hpp"
#include "coin.hpp"
class Initializer
{

public:
    Initializer();
    ~Initializer();

    std::vector<Participant> generate_random_participants(int number_of_participants);
    std::vector<Participant> generate_simple_participants(int number_of_participants);


private:
    Participant get_random_participant(std::string name);
    Participant get_participant( std::string name, double coin_value);
    Coin get_random_coin(int interval);
};



#endif // __INITIALIZER__
