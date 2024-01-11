# CompoundOfWealthSimulator
Simple blockchain simulator to test diffrent senarioes of reward giving


## Test Attributes Used:
    number_of_tests = 5000;
    double reward_value = 40;
    coin_value_a = 10;
    coin_value_b = 20;
    number_of_blocks = 1000;

## Sudo Code
    for i = 1 to number_of_tests:
        defining consense protocol to use 
        generate participants
        for j = 1 to number_of_blocks:
            get stakes from participants
            find winner stake
            distribute reward between participants based on consense protocol
            for all stakes:
                if stake.remaining_time = 0:
                    give stake back to participant
                else
                    stake.remaining_time --
            last_block_generated ++
