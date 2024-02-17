#include <iostream>
#include <string>
#include <random>

using namespace std;

string generatePassword(int minLength, int maxLength, string charSet) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> lengthDist(minLength, maxLength);
    uniform_int_distribution<> charDist(0, charSet.size() - 1);

    int passwordLength = lengthDist(generator);
    string password;

    for (int i = 0; i < passwordLength; ++i) {
        password += charSet[charDist(generator)];
    }
    return password;
}

string evaluatePasswordStrength(const string& password) {
    if (password.length() >= 12) return "Very High";
    else if (password.length() >= 8) return "High";
    else return "Low";
}

int main() {
    int minLength, maxLength;
    string charSet;

    cout << "Enter minimum password length: ";
    cin >> minLength;
    cout << "Enter maximum password length: ";
    cin >> maxLength;
    cout << "Include letters? (y/n): ";
    char includeLetters;
    cin >> includeLetters;
    if (includeLetters == 'y') charSet += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Include digits? (y/n): ";
    char includeDigits;
    cin >> includeDigits;
    if (includeDigits == 'y') charSet += "0123456789";
    cout << "Include symbols? (y/n): ";
    char includeSymbols;
    cin >> includeSymbols;
    if (includeSymbols == 'y') charSet += "!@#$%^&*()_-+=[]{};:<>?/";

    if (charSet.empty()) {
        cout << "No character types selected. Exiting program.\n";
        return 1;
    }

    string password = generatePassword(minLength, maxLength, charSet);
    cout << "Generated Password: " << password << endl;
    cout << "Password Strength: " << evaluatePasswordStrength(password) << endl;

    return 0;
}
