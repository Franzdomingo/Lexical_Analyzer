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
    unordered_set<string> keywords = {"int", "float", "return", "cout", "main", "using", "namespace", "std", "include", "iostream", "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile",
        "while"};
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
                cout << " " << token << " is a keyword" << endl;
            } else if (isalpha(token[0]) || token[0] == '_') {
                identifiersCount++;
                cout << " " << token << " is an identifier" << endl;
            } else if (token == "+" || token == "-" || token == "=" || token == "/" || token == "<<") {
                operatorsCount++;
                cout << " " << token << " is an operator" << endl;
            } else if (ispunct(token[0])) {
                symbolsCount++;
                cout << " " << token << " is a symbol" << endl;
            } else if (isdigit(token[0])) {
                constantsCount++;
                cout << " " << token << " is a constant" << endl;
            }
                cout << "—-SUMMARY—-" << endl;
                cout << "Keywords: " << keywordsCount << endl;
                cout << "Identifiers: " << identifiersCount << endl;
                cout << "Operators: " << operatorsCount << endl;
                cout << "Symbols: " << symbolsCount << endl;
                cout << "Constants: " << constantsCount << endl;

        }
    }

    inputFile.close();

    return 0;
}
