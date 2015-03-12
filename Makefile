
clean:
	rm -f program

build:
	g++ vigenere.cpp -o vigenere 
	./versioner.sh
