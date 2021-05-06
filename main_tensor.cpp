#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tensor.h"

void show_help(){
    printf("*** Tensors Operations ***\n");
    printf("\targ 1: input file name (tensor1) \n");
    printf("\targ 2: input file name (tensor2) \n");
    printf("\targ 3: operazione da effettuare (+,-,/,*,convolve, concat)\n");
    printf("\targ 4: output file name\n");
    printf("\targ 5: Diversi significati in funzione dell'operazione (default 3):\n"
           "\t\t- [smooth]: kernel size \n"
           "\t\t- [brighten]: valore bright per aumentare la luminosità \n"
           "\t\t\n");
    printf("\targ 6: Diversi significati in funzione dell'operazione (default 1.0):\n"
           "\t\t- [blend] parametro alpha per il blending di due immagini"); 
    printf("\n");
}

int main (int argc, char * argv[]) {

    char * fn_in_1;  /* file 1 */
    char * fn_in_2;  /* file 2 */
    char * operation; /* operazione da eseguire */
    char * fn_out; /* output file */

    int axis = 3; /* axis for concat */

    /* variabili di appoggio per le computazioni */
    Tensor a,b,out;

    if(argc<4){
        show_help();
        return 0;
    }

    fn_in_1 = argv[1];  /* file 1 */
    fn_in_2 = argv[2];  /* file 2 */
    operation = argv[3]; /* operazione da eseguire */
    fn_out = argv[4]; /* output file */

    if(argc>5) {
        axis = atoi(argv[5]);
    }

    a.read_file(fn_in_1);
    b.read_file(fn_in_2);
    
    if (strcmp(operation, "+") == 0) {
        out=a+b; /* aumenta la luminosità */
    }else if(strcmp(operation, "-") == 0) {
        out=a-b; /* aumenta la luminosità */
    }else if(strcmp(operation, "*") == 0) {
        out=a*b; /* aumenta la luminosità */
    }else if(strcmp(operation, "/") == 0) {
        out=a/b; /* aumenta la luminosità */
    }else if(strcmp(operation, "convolve") == 0) {
        out=a.convolve(b); /* aumenta la luminosità */
    }else if(strcmp(operation, "concat") == 0) {
        out=a.concat(b,axis); /* aumenta la luminosità */
    }else {
        throw(unknown_operation());
    }

    out.write_file(fn_out);

    return 0; /* ciao a tutti!*/
}