#if !defined(__STAKE__)
#define __STAKE__

#include <string>
#include <vector>

#include "participant.hpp"
#include "coin.hpp"

class Stake
{

public:
    Stake(std::vector<Coin> coins, int blocks_left, Participant *owner);
    ~Stake();


private:
    std::vector<Coin> coins;
    int blocks_left;
    Participant *owner;
};



#endif // __STAKE__
