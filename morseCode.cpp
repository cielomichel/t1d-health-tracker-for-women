#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    map<string, char> morseMap;

    ifstream file("MorseCode.txt");

    if (!file) {
        cout << "Could not open file" << "\n";
        return 1;
    }

    char letter;
    string code;

    while (file >> letter >> code) {
        morseMap.insert({code, letter});
    }

    file.close();

    string message = ".-. .. -.. -.. .-.. . / -- . / - .... .. ... / -... .- - -- .-.";
    stringstream ss(message);

    string currentCode;
    string decodedMessage = "";

    while (ss >> currentCode) {
        if (currentCode == "/") {
            decodedMessage += " ";
        } else {
            decodedMessage += morseMap[currentCode];
        }
    }

    cout << "Decoded message: " << decodedMessage << "\n";

    return 0;
}