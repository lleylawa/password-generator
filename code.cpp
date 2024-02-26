#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function to generate a random string based on user preferences
string generateRandomString(int length, bool includeDigits, bool includeLetters, bool includeSymbols) {
    string randomString; // Initialize an empty string to hold the generated password
    string charSet = ""; // Initialize an empty string to store the character set to be used
    string digits = "0123456789";
    string symbols = "!@#$%^&*()_-+=[]{};:<>?/";
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Append characters to the character set based on user preferences
    if (includeDigits)
        charSet += "0123456789"; // Include digits if requested
    if (includeLetters) {
        charSet += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Include letters if requested
    }
    if (includeSymbols) {
        charSet += "!@#$%^&*()_-+=[]{};:<>?/"; // Include symbols if requested
    }

    int charSetLength = charSet.length(); // Calculate the length of the character set

    // Ensure at least one character from each selected character set
    if (includeDigits && length > 0) {
        randomString += digits[rand() % digits.size()]; // Include one digit
        length --; // Decrease the remaining length accordingly
    }
    if (includeLetters &&length > 0) { 
        randomString += letters[rand() % letters.size()];
        length --; // Decrease the remaining length accordingly
    }    if (includeSymbols && length > 0) {
        randomString += symbols[rand() % symbols.size()]; // Include one symbol
        length --; // Decrease the remaining length accordingly
    }
    // Fill the remaining characters randomly from the combined character set
    for (int i = 0; i < length; ++i) {
        randomString += charSet[rand() % charSetLength]; // Append random characters from the character set
    }
    return randomString; // Return the generated password
}

// Function to evaluate the strength of a password based on its length
string evaluatePasswordStrength(const string& password) {
    if (password.length() >= 12) return "Very High"; 
    else if (password.length() >= 8) return "High";
    else return "Low"; 
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    int length;
    bool includeDigits, includeLetters, includeSymbols;

    // Prompt the user to enter preferences for password generation
    cout << "Enter the preferred length of the password: ";
    cin >> length;

    cout << "Do you want to include digits? (1/0): ";
    cin >> includeDigits;

    cout << "Do you want to include letters (uppercase and lowercase)? (1/0): ";
    cin >> includeLetters;

    cout << "Do you want to include symbols? (1/0): ";
    cin >> includeSymbols;

    // Ensure at least one character set is selected
    if (!(includeDigits || includeLetters || includeSymbols)) {
        cout << "At least one character set must be included. Exiting..." << endl;
        return 1; // Exit the program with an error code
    }

    // Generate a random password based on user preferences
    string password = generateRandomString(length, includeDigits, includeLetters, includeSymbols);
    cout << "Generated password: " << password << endl;
    cout << "Password Strength: " << evaluatePasswordStrength(password) << endl;
    return 0;
}
