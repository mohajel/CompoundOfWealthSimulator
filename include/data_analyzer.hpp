#if !defined(__DATA_ANALYZER__)
#define __DATA_ANALYZER__

#include <string>
#include <vector>


#include "participant.hpp"
#include "coin.hpp"

class DataAnalyzer
{

public:
    DataAnalyzer();
    ~DataAnalyzer();

    double calculate_gini_coefficient(std::vector<Participant> &participants);
    void write_to_file(std::vector<Participant> &participants, std::string file_name);

    // void analyze(const std::vector<Participant> &participants, const std::string &output_file_name);


private:


};

#endif // __DATA_ANALYZER__
