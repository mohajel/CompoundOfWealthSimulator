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
    Stake generate_stake();

    std::string get_name();

private:
    std::vector<Coin> coins;
    std::string name;
    float latancy; // 1 means no latancy
    bool is_participating;
};

#endif // __PARTICIPANT__
