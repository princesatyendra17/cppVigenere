#include <iostream>
#include <string>

using std::cout; 
using std::endl;

// Global configurations
enum Operation {NONE, ENCRYPT, DECRYPT, CRACK, PRINT};
const int OFFSET = 65;

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
Operation parseOptions(int argc, char **argv){
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

// Encrypt provided text using the provided key
void encrypt(char *key, char *text) {

    // Convert key to upper case
    int kCount = std::char_traits<char>::length(key);
    for (int i = 0; i < kCount; i++) {
        key[i] = toupper(key[i]);
    }

    int tCount = std::char_traits<char>::length(text);
    
    // Cycle through the text and key and shift each 
    // character in the text by the amount in the key
    for (int i = 0, k = 0; i < tCount; i++, k++) {
        text[i] = toupper(text[i]);

        if (k >= kCount) {
            k = 0;
        }
        int shift = (int)key[k] - 65;
        if (text[i] + shift > 90) {
            text[i] = (char)(text[i] + shift - 26);
        } else {
            text[i] = (char)(text[i] + shift);
        } 
    }
}

// Decrypt provided cipher text using the provided key
void decrypt(char *key, char *cipher) {

	// Convert key to upper case
	int kCount = std::char_traits<char>::length(key);
	for (int i = 0; i < kCount; i++) {
		key[i] = toupper(key[i]);
	}

	int tCount = std::char_traits<char>::length(cipher);

	// Cycle through the cipher and convert it to uppercase
	// and shift the characters to the unencrypted text
	for (int i = 0, k = 0; i < tCount; i++, k++) {
		cipher[i] = toupper(cipher[i]);

		if (k >= kCount) {
			k = 0;
		}
		int shift = (int)key[k] - 65;
		if (cipher[i] - shift < 65) {
			cipher[i] = (char)(cipher[i] - shift + 26);
		} else {
			cipher[i] = (char)(cipher[i] - shift);
		}
	}
}

// Crack provided cipher text using a dictionary attack
void crack(char *cipher) {
}

int main(int argc, char **argv) {
	if (argc < 2) {                                                                                           
		printHelp();                                                                                          
		return -1;                                                                                            
	}

    Operation op = parseOptions(argc, argv);
    char *key, *text, *cipher;

    switch (op) {
        case NONE   : printHelp(); break;
        case ENCRYPT: 
            cout << "ENCRYPT" << endl << endl; 
            key = argv[2];
            text = argv[3];
            encrypt(key, text);
            cout << text << endl;
            break;
        case DECRYPT: 
            cout << "DECRYPT" << endl << endl; 
            key = argv[2];
            cipher = argv[3];
            decrypt(key, cipher);
			cout << cipher << endl;
            break;
        case CRACK  : 
            cout << "CRACK" << endl << endl; 
            cipher = argv[2];
            //key = crack(cipher);
            //text = decrypt(key, cipher);
            break;
        case PRINT  : printTable(); break;
        default     : printHelp(); break;
    }

    return 0;
}
