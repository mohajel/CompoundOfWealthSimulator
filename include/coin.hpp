#if !defined(__COIN__)
#define __COIN__

#include <string>

class Coin
{
public:
    Coin(int value, int block_created);
    ~Coin();

private:
    int value;
    int block_created;
};

#endif // __COIN__
