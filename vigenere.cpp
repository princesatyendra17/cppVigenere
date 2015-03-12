#include <iostream>

using std::cout; 
using std::endl;

// Print command line help
void printHelp() {
    cout << "usage: vigenere [-p][-h]" << endl;
}

char getOption(char arg[], int j){
    return arg[j];
}

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

// Parse command line option
int parseOptions(int argc, char** argv){
        for(int i = 1; i < argc; i++){
            if (argv[i][0] == '-') {
                int j = 1;
                while(char c = getOption(argv[i], j)) {
                    j++;
                    switch (c) {
                        case 'h': printHelp(); return -1;
                        case 'e': cout << "Encrypt not yet added" << endl; return -1;
                        case 'd': cout << "Decrypt not yet added" << endl; return -1;
                        case 'c': cout << "Solve cipher not yet added" << endl; return -1;
                        case 'p': printTable(); break;
                        case 'k': cout << "Solve for key not yet added" << endl; return -1;
                        default : printHelp(); break;
                    }
                }
            } else {
                cout << argv[i] << endl;
            }
        }
}

int main(int argc, char** argv) {

    parseOptions(argc, argv);

    return 0;
}
