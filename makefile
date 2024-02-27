all: compile run

compile: 
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesiNode.o -c ./src/YoneticiListesiNode.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/ReadFile.o -c ./src/ReadFile.cpp
	g++ -I ./include/ -o ./lib/DisplayScreen.o -c ./src/DisplayScreen.cpp
	
	g++ -I ./include/ -o ./bin/main ./lib/SatirListesiNode.o ./lib/SatirListesi.o ./lib/YoneticiListesiNode.o ./lib/YoneticiListesi.o ./lib/ReadFile.o ./lib/DisplayScreen.o ./src/main.cpp

run:
	./bin/main