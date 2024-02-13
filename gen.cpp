#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int min, max;
    cout << "Enter the minimum password length: ";
    cin >> min;
    cout << "Enter the maximum password length: ";
    cin >> max;

    string password;
    string ex;

    // Prompt the user for each option
    char Symbols, Numbers, Upper, Lower;
    cout << "Include symbols? (y/n): ";
    cin >> Symbols;
    if (Symbols == 'y') {
        ex += "!@#$%^&*-_";
    }

    cout << "Include numbers? (y/n): ";
    cin >> Numbers;
    if (Numbers == 'y') {
        ex += "0123456789";
    }

    cout << "Include uppercase letters? (y/n): ";
    cin >> Upper;
    if (Upper == 'y') {
        ex += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    cout << "Include lowercase letters? (y/n): ";
    cin >> Lower;
    if (Lower == 'y') {
        ex += "abcdefghijklmnopqrstuvwxyz";
    }

    // Generate length
    int len = (max - min + 1);
    int length= rand () % len + min;
    // Generate passwordc
    for(int i = 0; i < length; i++) {
        password += ex[rand() % ex.length()];
    }

    cout << "Generated password: " << password << endl;

    //  password strength
    cout << "Strength of password: ";
    if (Lower == 'y' && Upper == 'y' && Numbers == 'y' && Symbols == 'y' && length > 8) {
        cout << "Strong" << endl;
    } else if ((Lower == 'y' || Upper == 'y') && Numbers == 'y' && length > 6) {
        cout << "Average" << endl;
    } else {
        cout << "Weak" << endl;
    }

    return 0;
}
