#ifndef DAIS_EXC
#define DAIS_EXC

#include <string>

using namespace std;

/* Expections */
struct index_out_of_bound{
    string msg = "Index out of bound";
    string code = "001";
};

struct dimension_mismatch{
    string msg = "Dimensions Mismatch";
    string code = "002";
};

struct unknown_operation{
    string msg = "Unknown Operation";
    string code = "003";
};

struct method_not_implemented{
    string msg = "Method not implemented";
    string code = "004";
};

struct tensor_not_initialized{
    string msg = "Tensor not initilized";
    string code = "005";
};

struct concat_wrong_dimension{
    string msg = "Concatenation on wrong dimension";
    string code = "006";
};

struct unable_to_read_file{
    string msg = "Unable to read file";
    string code = "007";   
};

struct filter_odd_dimensions{
    string msg = "The (width and height) dimensions of the filter must be odd";
    string code = "008";   
};


#endif

