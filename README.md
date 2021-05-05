# DAISGram
Repository per il progetto di Laboratorio di Programmazione A.A. 2020-2021

I dettagli del progetto sono visibili [qui](https://docs.google.com/document/d/1G9mSJaCNfDTd1uzwQlgYWjXfUNXsz7EzLuoDCranRHU/edit#)

La cartella `images` contiene alcune immagini con cui potete provare la vostra implementazione.

Nella cartella `results` trovate invece i risultati attesi dai seguenti metodi.
Immagine | Brighten (+20) | Brighten (+100) | Grayscale
------------ | ------------- | ------------- |-------------
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/dais.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_brighten_20.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_brighten_100.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_gray.bmp) 

Immagine | Smooth (h=3) | Smooth (h=5) | Smooth (h=7)
------------ | ------------- | ------------- |------------- 
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/dais.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_smooth_3.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_smooth_5.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_smooth_7.bmp) 

Immagine | Sharp | Warhol | Equalize
------------ | ------------- | ------------- |------------- 
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/dais.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_sharp.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_warhol.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_equalize.bmp) |

## Libreria per BMP
Per testare il corretto funzionamento della libreria (libbmp) dovete lanciare il comando `make testbmp` e successivamente `./test_bmp`.

Se tutto è andato bene dovrebbe generare una scacchiera.

![Checkboard](https://github.com/xwasco/DAISGram_20_21/blob/main/checkboard.bmp)
