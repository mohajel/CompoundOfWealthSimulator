#if !defined(__PARTICIPANT__)
#define __PARTICIPANT__

#include <string>
#include <vector>

#include "coin.hpp"

class Participant
{

public:
    Participant(float latancy = 1, bool is_participating = true);
    ~Participant();

    void add_coin(Coin coin);

private:
    std::vector<Coin> coins;
    float latancy; // 1 means no latancy
    bool is_participating;
};

#endif // __PARTICIPANT__
