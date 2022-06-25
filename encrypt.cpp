#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void encodingFunction(string &newStr, bool isX, char temp, int x, int y, string str) {
    temp = '0' + x;
    newStr[0] = temp;
    temp = '0' + y;
    newStr[newStr.length() - 1] = temp;

    // Creates the new encrypted string
    for(int i = 0; i < str.length(); i++) {
        if (isX) {
            newStr[i+1] = str[i] + x;
            isX = false;
        }
        else {
            newStr[i+1] = str[i] + y;
            isX = true;
        }
    }
}

int main(int argc, char *argv[])
{
    // Seeding the rand() function
    srand(time(0));
    int x = (rand() % 5) + 1, 
        y = (rand() % 4) + 1;
    char temp = '0';
    // 'X' value, which is just the representation of an odd/even place
    bool isX = false;
    string str;

    // Simple 1 message at a time from the command line
    if (argc == 1) {
        cout << "Please enter a string to get encoded:\t";
        getline(cin, str);

        string newStr (str.length() + 2, 'x');
        encodingFunction(newStr, isX, temp, x, y, str);

        cout << "\nEncoded string: " << newStr << endl;
    }
    // Mass encoding using file from Command Line Arguments
    else {
        ifstream inFile;
        ofstream outFile;
        outFile.open("toDecrypt.txt");
        inFile.open(argv[1]);
        str.clear();

        // Verify both of the files successfully opened before reading/writing
        if (inFile.is_open() && outFile.is_open()) {
            // Read until EOF
            while (getline(inFile, str)) {
                // Change values each time for different encryption
                x = (rand() % 5) + 1, 
                y = (rand() % 4) + 1;
                // Reset these variables to match
                temp = '0';
                isX = false;

                string newStr (str.length() + 2, 'x');
                encodingFunction(newStr, isX, temp, x, y, str);

                outFile << newStr << endl;

                str.clear();
            }
        }

        inFile.close();
        outFile.close();
    }
       
    return 0;
}