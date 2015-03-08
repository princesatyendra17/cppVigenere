#include <iostream>

using std::cout; 
using std::endl;

// Print out an all capital letter version of a vigenere table using standard English characters.
void printTable() {
    char a = 'A', z='Z';
    int offset = 0;
    
    for(char c = a; c <= z; c++) {
        for(char i = a + offset; i <= z + offset; i++) {
            cout << (char)(i <= z ? i : i - 26) << " "  ;
        }
        offset++;
        cout << endl;
     }
}

int main(int argc, char** argv) {

    printTable();

    return 0;
}
