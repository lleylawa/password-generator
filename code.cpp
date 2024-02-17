#include <iostream>
#include <string>
#include <random>

using namespace std;

// Function to generate a random password
string generatePassword(int minLength, int maxLength, string charSet) {
    // Random number generator setup
    random_device rd;
    mt19937 generator(rd());
    // Distribution for selecting password length
    uniform_int_distribution<> lengthDist(minLength, maxLength);
    // Distribution for selecting characters from the character set
    uniform_int_distribution<> charDist(0, charSet.size() - 1);

    // Generate random password length within the specified range
    int passwordLength = lengthDist(generator);
    string password;

    // Construct the password by randomly selecting characters from the character set
    for (int i = 0; i < passwordLength; ++i) {
        password += charSet[charDist(generator)];
    }
    return password;
}

// Function to evaluate password strength based on its length
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
    
    // Include letters
    if (includeLetters == 'y') charSet += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Include digits? (y/n): ";
    char includeDigits;
    cin >> includeDigits;
    // Include digits
    if (includeDigits == 'y') charSet += "0123456789";
    cout << "Include symbols? (y/n): ";
    char includeSymbols;
    cin >> includeSymbols;
    // Include symbols
    if (includeSymbols == 'y') charSet += "!@#$%^&*()_-+=[]{};:<>?/";

    // If no character types are selected, exit the program
    if (charSet.empty()) {
        cout << "No character types selected. Exiting program.\n";
        return 1;
    }

    // Generate a password based on the provided criteria
    string password = generatePassword(minLength, maxLength, charSet);

    cout << "Generated Password: " << password << endl;
    cout << "Password Strength: " << evaluatePasswordStrength(password) << endl;

    return 0;
}
