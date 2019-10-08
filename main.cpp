#include <descriptive_statistics.hpp>
#include <tclap/CmdLine.h>

void process_cmd_line_args(int argc, char** argv);

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    process_cmd_line_args(argc, argv);
    
    std::string temporary_line{};
    std::vector<double> data{};
    data.reserve(1024);
    while(std::cin>> temporary_line) {
        data.emplace_back(std::atof(temporary_line.c_str()));
    }

    if(! std::is_sorted(data.cbegin(), data.cend()) ) {
        std::sort(data.begin(), data.end());
    }

    std::cout<< DS(&*data.cbegin(), &*data.cend()) ;
    
    return(EXIT_SUCCESS);
}

void process_cmd_line_args(int argc, char** argv) {

    try {
        TCLAP::CmdLine cmd("Descriptive Stats Tool", ' ', "0.1");
        TCLAP::SwitchArg verbose_flag("v","verbose","Print value labels", cmd, false);
        TCLAP::SwitchArg all_stats_flag("w","all","Print all stats", cmd, false);
        TCLAP::SwitchArg min_flag("m","min","Print minimum value", cmd, false);
        TCLAP::SwitchArg first_quartile_flag("f","first-quartile","Print first quartile", cmd, false);
        TCLAP::SwitchArg mean_flag("a","mean","Print mean value", cmd, false);
        TCLAP::SwitchArg median_flag("A","median","Print median value", cmd, false);
        TCLAP::SwitchArg third_quartile_flag("t","third-quartile","Print third quartile", cmd, false);
        TCLAP::SwitchArg max_flag("M","max","Print maximum value", cmd, false);
        TCLAP::SwitchArg sum_flag("s","sum","Print sum of values", cmd, false);
        TCLAP::SwitchArg variance_flag("V","variance","Print variance", cmd, false);
        TCLAP::SwitchArg standard_deviation_flag("e","standard-deviation","Print standard deviation", cmd, false);
	
	    cmd.parse( argc, argv );

        DS::VERBOSE = verbose_flag.getValue();
        DS::ALL_STATS = all_stats_flag.getValue();
        DS::MIN = min_flag.getValue();
        DS::FIRST_QUARTILE = first_quartile_flag.getValue();
        DS::MEAN = mean_flag.getValue();
        DS::MEDIAN = median_flag.getValue();
        DS::THIRD_QUARTILE = third_quartile_flag.getValue();
        DS::MAX = max_flag.getValue();
        DS::SUM = sum_flag.getValue();
        DS::VARIANCE = variance_flag.getValue();
        DS::STANDARD_DEVIATION  = standard_deviation_flag.getValue();

    } catch( TCLAP::ArgException &e ) {
        std::cerr<< e.error() << std::endl;
    }

}