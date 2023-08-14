#if !defined(__STAKE__)
#define __STAKE__

#include <string>
#include <vector>

#include "coin.hpp"

class Participant;
class Stake
{

public:
    Stake(std::vector<Coin> coins, int blocks_left, Participant *owner);
    ~Stake();

    void print_status();

    bool is_empty();
    bool update_stake();
    double get_totall_coins_value();
    
    std::vector<Coin> coins;
    Participant *owner;

private:
    int blocks_left;
};



#endif // __STAKE__
