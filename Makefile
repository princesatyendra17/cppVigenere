
clean:
	rm -f program

build:
	g++ vigenere.cpp -o program
	./versioner.sh
