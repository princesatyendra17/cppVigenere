
clean:
	rm -f program

build:
	g++ -std=c++11 vigenere.cpp -o vigenere 
	./versioner.sh
