# DAISGram
Repository per il progetto di Laboratorio di Programmazione A.A. 2020-2021

I dettagli del progetto sono visibili [qui](https://docs.google.com/document/d/1G9mSJaCNfDTd1uzwQlgYWjXfUNXsz7EzLuoDCranRHU/edit#)

La composizione dei gruppi invece è a [questo foglio](https://docs.google.com/spreadsheets/d/1oAY-lWT7S9lwcnfZ0ncD7lZIeZl01kDjGVEBeHfo7nA/edit#gid=0)

## Libreria per BMP
Per testare il corretto funzionamento della libreria (libbmp) dovete lanciare il comando `make testbmp` e successivamente `./test_bmp`.

Se tutto è andato bene dovrebbe generare una scacchiera.

![Checkboard](https://github.com/xwasco/DAISGram_20_21/blob/main/checkboard.bmp)

# Risultati Attesi
La cartella `images` contiene alcune immagini con cui potete provare la vostra implementazione.

Nella cartella `results` trovate invece i risultati attesi.

Immagine | Brighten (+20) | Brighten (+100) | Grayscale
------------ | ------------- | ------------- |-------------
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/dais.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_brighten_20.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_brighten_100.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_gray.bmp) 

Immagine | Smooth (h=3) | Smooth (h=5) | Smooth (h=7)
------------ | ------------- | ------------- | ------------- 
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/dais.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_smooth_3.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_smooth_5.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_smooth_7.bmp) 

Immagine | Sharp | Edge | Warhol
------------ | ------------- | ------------- | ------------- 
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/dais.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_sharp.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_edge.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/dais_warhol.bmp) | 

Immagine A | Immagine B | Blend alpha=0 | alpha=0.25 | alpha=0.5 | alpha=0.75 | alpha=1.00
------------ | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- 
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/blend/blend_a.bmp) | ![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/blend/blend_b.bmp) | ![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/results/blend/blend_0.00.bmp) | ![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/results/blend/blend_0.25.bmp) | ![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/results/blend/blend_0.50.bmp) | ![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/results/blend/blend_0.75.bmp) | ![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/results/blend/blend_1.00.bmp) 

# Parti Opzionali
## Green Screen
Primo Piano | Sfondo | GreenScreen
------------ | ------------- | -------------
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/greenscreen/gs_2.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/images/greenscreen/gs_2_bkg.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/greenscreen/dais_matrix.bmp)
 | | | RGB={144, 208, 49}, threshold={100, 100, 50}
 |  |  | 
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/greenscreen/gs_4.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/images/greenscreen/gs_4_bkg.bmp) | ![DAIS+100](https://github.com/xwasco/DAISGram_20_21/blob/main/results/greenscreen/seba_flower.bmp)
 | | | RGB={226,225,220}, threshold={50,50,50}
 
 ## Equalizzazione dell'istogramma
 Immagine Originale | Equalizzata
------------ | -------------
![DAIS](https://github.com/xwasco/DAISGram_20_21/blob/main/images/fullmoon.bmp) | ![DAIS+20](https://github.com/xwasco/DAISGram_20_21/blob/main/results/fullmoon_equalize.bmp)
