#include <algorithm>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>

#include <descriptive_statistics.hpp>

bool DS::VERBOSE;
bool DS::ALL_STATS;
bool DS::MIN;
bool DS::FIRST_QUARTILE;
bool DS::MEAN;
bool DS::MEDIAN;
bool DS::THIRD_QUARTILE;
bool DS::MAX;
bool DS::SUM;
bool DS::VARIANCE;
bool DS::STANDARD_DEVIATION;

DS::DS(const double* begin, const double* end) {

    const std::size_t size = std::distance(begin, end) ;

    min = *begin;    

    first_quartile = begin[ size/4 ] ;

    sum = std::accumulate(begin, end, double{});

    mean = sum / size ;

    const std::size_t idx{ size  / 2 };
    median = begin[ idx ] ;
    if( ! (size & 1) ) {      
        median += begin[ idx - 1 ];
        median *= 0.5;
    }

    third_quartile = begin[ 3*size/4 ] ; 

    variance = std::accumulate(begin, end, double{}, [&] (double a, double b) {
                   return a + std::pow(b - mean, 2.0); 
               }) / size ;

    standard_deviation = std::sqrt(variance);  

    max = *std::prev(end);   
}

DS::DS(const double* begin, std::size_t length) {
    const double* end = begin + length;
    *this = DS(begin,end);
}

std::ostream& operator<<(std::ostream& os, const DS& ds) {
   
    if(DS::MIN || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "min: " : "") << ds.min << '\n';
    if(DS::FIRST_QUARTILE || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "first quartile: " : "") << ds.first_quartile << '\n';
    if(DS::MEAN || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "mean: " : "") << ds.mean  << '\n';
    if(DS::MEDIAN || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "median: " : "") << ds.median << '\n';
    if(DS::THIRD_QUARTILE || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "third quartile: " : "") << ds.third_quartile << '\n';
    if(DS::MAX || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "max: " : "") << ds.max << '\n';
    if(DS::SUM || DS::ALL_STATS)
        os << (DS::VERBOSE ? "sum: " : "") << ds.sum << '\n';
    if(DS::VARIANCE || DS::ALL_STATS)
        os << (DS::VERBOSE ? "variance: " : "") << ds.variance << '\n';
    if(DS::STANDARD_DEVIATION || DS::ALL_STATS) 
        os << (DS::VERBOSE ? "standard deviation: " : "") << ds.standard_deviation << '\n';

    return os;
}


