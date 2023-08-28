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
    virtual void distribute_rewards(Stake &winner_stake, std::vector<Stake> &stakes, double reward_value, int last_block_number);
    double get_total_stakes_value(std::vector<Stake> &stakes);
    double get_total_participants_value(std::vector<Participant> &participants);
    
private:    
};


class ZahraConsenseProtocol : public ConsenseProtocol
{

public:
    ZahraConsenseProtocol();
    ~ZahraConsenseProtocol();

    void distribute_rewards(Stake &winner_stake, std::vector<Stake> &stakes, double reward_value, int last_block_number) override;
    
private:
};

#endif // __CONSENSE_PROTOCOL__


