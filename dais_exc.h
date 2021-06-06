#ifndef DAIS_EXC
#define DAIS_EXC

#include <string>

using namespace std;

/* Expections */
struct index_out_of_bound{
    string msg = "Index out of bound";
    string code = "001";
    /* Utilizzate questa eccezione per i casi di accesso a locazioni errate dei tensori 
    (ad esempio indici negativi o superiori alle dimensioni del tensore) */
};

struct dimension_mismatch{
    string msg = "Dimensions Mismatch";
    string code = "002";
    /* Utilizzate questa eccezione per i casi in cui l'operazione tra due tensori richieda
    le stesse dimensioni */
};

struct unknown_operation{
    string msg = "Unknown Operation";
    string code = "003";
    /* Utilizzate questa eccezione per i casi in cui l'operazione da eseguire non è conosciuta */
};

struct method_not_implemented{
    string msg = "Method not implemented";
    string code = "004";
    /* Utilizzate questa eccezione se non volete implementare una certa funzione */
};

struct tensor_not_initialized{
    string msg = "Tensor not initilized";
    string code = "005";
    /* Utilizzate questa eccezione se il tensore non è inizializzato */
};

struct concat_wrong_dimension{
    string msg = "Concatenation on wrong dimension";
    string code = "006";
    /* Utilizzate questa eccezione se la dimensione sulla quale volete eseguire la concatenazione è errata */
};

struct unable_to_read_file{
    string msg = "Unable to read file";
    string code = "007";   
    /* Utilizzate questa eccezione se il file dal quale volete leggere un tensore non esiste */
};

struct filter_odd_dimensions{
    string msg = "The (width and height) dimensions of the filter must be odd";
    string code = "008";   
    /* Utilizzate questa eccezione se il filtro per la convoluzione NON ha dimensioni (altezza e largezza) dispari */
};

struct unknown_exception{
    string msg = "An error occured";
    string code = "-1";   
    /* Utilizzate questa eccezione per qualsiasi tipo di problema non gestito da altre eccezioni */
};


#endif

