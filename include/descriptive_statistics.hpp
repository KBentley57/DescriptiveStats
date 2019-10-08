#ifndef DESCRIPTIVE_STATISTICS_HPP
#define DESCRIPTIVE_STATISTICS_HPP

#include<fstream>
#include<iostream>

class alignas(16) DS {

public:
    DS() = default;
    DS(const DS& ) = default;
    DS(DS&& ) = default;
    DS(const double*, std::size_t length);
    DS(const double*, const double*);
    virtual ~DS() = default;

    DS& operator=(const DS& ) = default;
    DS& operator=(DS&& ) = default;

    friend std::ostream& operator<<(std::ostream& , const DS& );
    std::ostream& plot(std::ostream& os, int N) const;

    bool operator<(const DS& ) = delete;
    bool operator>(const DS& ) = delete;
    bool operator==(const DS& ) = delete;

    static bool VERBOSE;
    static bool ALL_STATS;
    static bool MIN;
    static bool FIRST_QUARTILE;
    static bool MEAN;
    static bool MEDIAN;
    static bool THIRD_QUARTILE;
    static bool MAX;
    static bool SUM;
    static bool VARIANCE;
    static bool STANDARD_DEVIATION;

private:
    double min;
    double first_quartile;
    double mean;
    double median;
    double third_quartile;
    double max;
    double sum;
    double variance;
    double standard_deviation;
};

#endif