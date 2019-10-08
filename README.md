# DescriptiveStats
A small command line utility to quickly generate basic descriptive stats from stdin


USAGE: 

   ./ds  [-e] [-V] [-s] [-M] [-t] [-A] [-a] [-f] [-m] [-w] [-v] [--]
         [--version] [-h]


Where: 

   -e,  --standard-deviation
     Print standard deviation

   -V,  --variance
     Print variance

   -s,  --sum
     Print sum of values

   -M,  --max
     Print maximum value

   -t,  --third-quartile
     Print third quartile

   -A,  --median
     Print median value

   -a,  --mean
     Print mean value

   -f,  --first-quartile
     Print first quartile

   -m,  --min
     Print minimum value

   -w,  --all
     Print all stats

   -v,  --verbose
     Print value labels

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.


   Descriptive Stats Tool
   
EXAMPLE - Print all stats from a sequence of inputs\

$ seq 1 100 | ./ds -wv\
min: 1\
first quartile: 26\
mean: 50.5\
median: 50.5\
third quartile: 76\
max: 100\
sum: 5050\
variance: 833.25\
standard deviation: 28.8661\

EXAMPLE - Print the median without the verbose label\

$ seq 1 11 | ./ds -A\
6
