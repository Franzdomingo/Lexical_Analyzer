#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <unordered_set>

using namespace std;

// Function to check if a token is a keyword
bool isKeyword(const string& token) {
    unordered_set<string> keywords = {"if", "else", "while", "int", "float", "return"};
    return keywords.count(token) > 0;
}

int main() {
    string filename = "sourceFile.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    string line;
    int keywordsCount = 0;
    int identifiersCount = 0;
    int operatorsCount = 0;
    int symbolsCount = 0;
    int constantsCount = 0;

    while (getline(inputFile, line)) {
        istringstream inputStream(line);
        string token;

        while (inputStream >> token) {
            if (isKeyword(token)) {
                keywordsCount++;
            } else if (isalpha(token[0]) || token[0] == '_') {
                identifiersCount++;
            } else if (token == "+" || token == "-" || token == "*" || token == "/") {
                operatorsCount++;
            } else if (ispunct(token[0])) {
                symbolsCount++;
            } else if (isdigit(token[0])) {
                constantsCount++;
            }
        }
    }

    inputFile.close();

    cout << "—-SUMMARY—-" << endl;
    cout << "Keywords: " << keywordsCount << endl;
    cout << "Identifiers: " << identifiersCount << endl;
    cout << "Operators: " << operatorsCount << endl;
    cout << "Symbols: " << symbolsCount << endl;
    cout << "Constants: " << constantsCount << endl;

    return 0;
}