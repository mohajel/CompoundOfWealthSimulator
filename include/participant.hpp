#if !defined(__PARTICIPANT__)
#define __PARTICIPANT__

#include <string>

class Participant
{

public:
    Participant(float latancy = 1, bool is_participating = true);
    ~Participant();


private:
   float latancy; // 1 means no latancy
   bool is_participating;
};



#endif // __PARTICIPANT__
