#if !defined(__SIMULATOR__)
#define __SIMULATOR__

#include <string>
#include <vector>

#include "participant.hpp"
#include "stake.hpp"
#include "consense_protocol.hpp"

class Simulator
{

public:
    Simulator(ConsenseProtocol* cp, double rw, int block_duration = 1);
    ~Simulator();

    void run(int number_of_blocks);
    void add_participants(std::vector<Participant> participants);
    void add_participants(Participant participant);
    std::vector<Participant> get_participants();

private:
    void print_stakes_status();
    void print_participants_status();

    void get_stakes_from_participants();
    void update_stakes();

    int last_block_number;
    const double reward_value;
    int stake_duration;

    ConsenseProtocol* consense_protocol;

    std::vector<Participant> participants;
    std::vector<Stake> stakes;
};



#endif // __SIMULATOR__
