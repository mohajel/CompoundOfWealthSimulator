#if !defined(__COIN__)
#define __COIN__

#include <string>

class Coin
{
public:
    Coin(int value, int block_created);
    ~Coin();

    double get_value();
    int get_block_created();

private:
    double value;
    int block_created;
};

#endif // __COIN__
