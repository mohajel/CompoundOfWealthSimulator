#if !defined(__PARTICIPANT__)
#define __PARTICIPANT__

#include <string>
#include <vector>

#include "coin.hpp"
#include "stake.hpp"

class Stake;

class Participant
{

public:
    Participant(std::string name, int type = 0, float latancy = 1, bool is_participating = true);
    ~Participant();

    void print_status();

    void add_coin(Coin coin);
    void add_coin(std::vector<Coin> coins);
    Stake generate_stake(int stake_duration = 1);
    Stake generate_stake_initial_invest(int stake_duration = 1);

    std::string get_name();
    double get_totall_coins_value();

private:
    double initial_coin_percentage;
    std::vector<Coin> coins;
    std::string name;
    float latancy; // 1 means no latancy
    bool is_participating;
    int type;
};

#endif // __PARTICIPANT__
