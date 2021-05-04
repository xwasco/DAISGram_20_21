MAIN = main

all: main

debug: FLAGS=-Wall -g
debug: main

tensor.o: tensor.h
	g++ tensor.h -o tensor.o -O1 -c $(FLAGS)

libbmp.o: libbmp.cpp libbmp.h
	g++  libbmp.cpp -o libbmp.o -O1 -c

DAISGram.o: DAISGram.h
	g++ DAISGram.h -o DAISGram.o -O1 -c $(FLAGS)

main: main.cpp tensor.o DAISGram.o libbmp.o
	g++ main.cpp -o $(MAIN) -O1 $(FLAGS)

testbmp: test_bmplib.cpp libbmp.o
	g++ libbmp.o test_bmplib.cpp -o test_bmplib -O1 $(FLAGS)

clean:
	rm $(MAIN) *.o