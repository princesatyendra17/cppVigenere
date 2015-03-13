#include <iostream>

using std::cout; 
using std::endl;
using std::string;

// Global configurations
enum OPERATION {NONE, ENCRYPT, DECRYPT, CRACK, PRINT};

// Print command line help
void printHelp() {
    cout << "usage: vigenere [-h | -e key text| -d key cipher | -c cipher | -p | -h]" << endl;
    cout << "\tOptions: " << endl;
    cout << "\t\t-h\tPrint this help message" << endl << endl;
    cout << "\t\t-e\tRequires 2 arguments. Uses the provided key to\n\t\t\tencrypt the text." << endl << endl;
    cout << "\t\t-d\tRequires 2 arguments. Uses the provided key to\n\t\t\tdecrypt the cipher." << endl << endl;
    cout << "\t\t-c\tRequires 1 argument. Attempts to decode the\n\t\t\tprovided cipher." << endl << endl;
    cout << "\t\t-p\tPrints a table displaying the standard values\n\t\t\tof a vignere cipher." << endl << endl;
}

// Print out an all capital letter version of a vigenere table using standard English characters.
void printTable() {
    char a = 'A', z='Z';
    int offset = 0;
    cout << endl;            
    for(char c = a; c <= z; c++) {
        cout << "\t" <<c << " | ";
        for(char i = a + offset; i <= z + offset; i++) {
            cout << (char)(i <= z ? i : i - 26) << " "  ;
        }   
        offset++;
        cout << endl;
    }   
    cout << endl;
}

// Parse command line option
OPERATION parseOptions(int argc, char** argv){
    char c; 
    if (argv[1][0] = '-') {
        c = argv[1][1];
    } else {
        return NONE;
    }
    
    switch (c) {
        case 'h': return NONE;
        case 'e': return argv[2] ? (argv[3] ? ENCRYPT : NONE) : NONE;
        case 'd': return argv[2] ? (argv[3] ? DECRYPT : NONE) : NONE;
        case 'c': return argv[2] ? CRACK : NONE;
        case 'p': return PRINT;
        default : return NONE;
    }
}

int main(int argc, char** argv) {
    OPERATION op = parseOptions(argc, argv);
    char* key, * text, * cipher;

    switch (op) {
        case NONE   : printHelp(); break;
        case ENCRYPT: 
            cout << "ENCRYPT" << endl << endl; 
            key = argv[2];
            text = argv[3];
            break;
        case DECRYPT: 
            cout << "DECRYPT" << endl << endl; 
            key = argv[2];
            cipher = argv[3];
            break;
        case CRACK  : 
            cout << "CRACK" << endl << endl; 
            cipher = argv[2];
            break;
        case PRINT  : printTable(); break;
        default     : printHelp(); break;
    }

    return 0;
}
