#if !defined(__CONSENSE_PROTOCOL__)
#define __CONSENSE_PROTOCOL__

#include <string>
#include <vector>


#include "participant.hpp"
#include "coin.hpp"
#include "stake.hpp"

class ConsenseProtocol
{

public:
    ConsenseProtocol();
    ~ConsenseProtocol();

    Stake find_winner_stake(std::vector<Stake> &stakes);
private:
};

#endif // __CONSENSE_PROTOCOL__
