#include <iostream>
using namespace std;

int main()
{
    string str, x, y;
    int xNum, yNum;
    bool isX = false;

    cout << "Please enter the encoded message:\t";
    cin >> str;

    // This prints a bouquet of ASCII flowers from a hard-coded string <3
    if (str == "DayOneTreat") {
         cout << "          -=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-\n\n              __        __        __        __\n .*.        /~ .~\\    /~  ~\\    /~ .~\\    /~  ~\\ \n ***       '      `\\/'      *  '      `\\/'      *\n  V       (                .*)(               . *)\n/\\|/\\      \\    Camila  . *./  \\     Hayden . *./\n  |         `\\ .      . .*/'    `\\ .      . .*/'       .*.\n  |           `\\ * .*. */' _    _ `\\ * .*. */'         ***\n                `\\ * */'  ( `\\/'*)  `\\ * */'          /\\V\n                  `\\/'     \\   */'    `\\/'              |/\\ \n                            `\\/'                        |\n                            LOVES\n        ";
    }
    else {
        x = str[0], y = str[str.length()-1];

        xNum = stoi(x);
        yNum = stoi(y);
    
        cout << "\nDecoded <3: ";
        for(int i = 1; i < str.length() - 1; i++) {
            if (isX)  {
                str[i] = str[i] - xNum;
                isX = false;
            }
            else {
                str[i] = str[i] - yNum; 
                isX = true;
            }
            cout << str[i];
        }
        cout << endl;
    }
        
    return 0;
}