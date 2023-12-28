#if !defined(__PARTICIPANT__)
#define __PARTICIPANT__

#include <string>
#include <vector>

#include "coin.hpp"

class Stake;

class Participant
{

public:
    Participant(std::string name, float latancy = 1, bool is_participating = true);
    ~Participant();

    void print_status();
    
    void add_coin(Coin coin);
    void add_coin(std::vector<Coin> coins);
    Stake generate_stake(int stake_duration = 1);

    std::string get_name();
    double get_totall_coins_value();

    double initial_coin_percentage;
    std::vector<Coin> coins;

private:
    std::string name;
    float latancy; // 1 means no latancy
    bool is_participating;
};

// this participant only invests its initial coin not rewards. used for creatiing pow result
class InitialInvestParticipant : public Participant
{
    InitialInvestParticipant(std::string name, float latancy = 1, bool is_participating = true);
    ~InitialInvestParticipant();

    Stake generate_stake(int stake_duration = 1);   
};

#endif // __PARTICIPANT__
