#if !defined(__CONSENSE_PROTOCOL__)
#define __CONSENSE_PROTOCOL__

#include <string>
#include <vector>


#include "participant.hpp"
#include "coin.hpp"

class ConsenseProtocol
{

public:
    ConsenseProtocol();
    ~ConsenseProtocol();

    Participant find_winner_participant(std::vector<Participant> &participants);
private:
};

#endif // __CONSENSE_PROTOCOL__
