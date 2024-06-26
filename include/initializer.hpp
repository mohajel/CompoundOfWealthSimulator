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
    std::vector<Participant> generate_two_participants(int first_participant_coins_value, int second_participant_coins_value);
    std::vector<Participant> generate_two_pow_participants(int first_participant_coins_value, int second_participant_coins_value);
    Participant get_participant(std::string name, double coin_value);

private:
    Participant get_random_participant(std::string name);
    Participant get_participant_pow(std::string name, double coin_value);
    Coin get_random_coin(int interval);
};



#endif // __INITIALIZER__
