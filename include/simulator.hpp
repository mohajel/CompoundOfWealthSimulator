#if !defined(__SIMULATOR__)
#define __SIMULATOR__

#include <string>
#include <vector>

#include "participant.hpp"

class Simulator
{

public:
    Simulator(/* args */);
    ~Simulator();

    void run();

    void add_participants(std::vector<Participant> participants);
    void add_participants(Participant participant);


private:
    std::vector<Participant> participants;
};



#endif // __SIMULATOR__
