#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tensor.h"
#include "libbmp.h"
#include "DAISGram.h"


void show_help(){
    printf("*** DAISGram ***\n");
    printf("\targ 1: input file name (img1) \n");
    printf("\targ 2: input file name (img2) \n");
    printf("\targ 3: operazione da effettuare (gray, brighten, blend, sharp, edge, emboss, smooth, warhol, equalize, chromakey) \n");
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

    int k_size = 3; /* kernel size */
    float alpha = 1.; /* alpha della blend */

    /* variabili di appoggio per le computazioni */
    DAISGram b, c, img;

    if(argc<4){
        show_help();
        return 0;
    }

    fn_in_1 = argv[1];  /* file 1 */
    fn_in_2 = argv[2];  /* file 2 */
    operation = argv[3]; /* operazione da eseguire */
    fn_out = argv[4]; /* output file */

    if(argc>5) {
        k_size = atoi(argv[5]);
    }

    if(argc>6){
        alpha = atof(argv[6]);
    }

    b.load_image(fn_in_1);  /* leggi il file di input */

    if (strcmp(operation, "brighten") == 0) {
        img = b.brighten(k_size); /* aumenta la luminosità */
    }
    else if (strcmp(operation, "blend") == 0) {
        cout<<alpha<<endl;
        c.load_image(fn_in_2);        
        img = b.blend(c, alpha); /* effettua il blending di due immagini */
    }else if (strcmp(operation, "gray") == 0) {
        img = b.grayscale();
    }
    else if (strcmp(operation, "equalize") == 0) {
        img = b.equalize();
    }else if (strcmp(operation, "chromakey") == 0) {
        c.load_image(fn_in_2); 
        int r_,g_,b_;
        float thr,thg,thb;
        cout<<"Enter green-screen parameters (int RGB[3]) and (float RGB Threshold[3])"<<endl;
        cin>>r_>>g_>>b_>>thr>>thg>>thb;
        int rgb[3]={r_,g_,b_};
        float th[3]={thr,thg,thb};
        img = b.greenscreen(c,rgb,th);
    }else if (strcmp(operation, "sharp") == 0) {
        img = b.sharpen(); 
    }else if (strcmp(operation, "edge") == 0) {
        img = b.edge();
    }else if (strcmp(operation, "emboss") == 0) {
        img = b.emboss();
    }else if (strcmp(operation, "smooth") == 0) {
        img = b.smooth(k_size);
    }else if (strcmp(operation, "warhol") == 0) {
        img = b.warhol();
    }else {
        throw(unknown_operation());
    }

    img.save_image(fn_out);

    return 0; /* ciao a tutti!*/
}