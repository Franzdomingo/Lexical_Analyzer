#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <cctype>
#include <unordered_set>

using namespace std;

// Function to check if a token is a keyword
bool isKeyword(const string &token)
{
    unordered_set<string> keywords = {"cout", "cin", "auto", "bool", "break", "case", "catch", "char","class","const", 
                                      "continue", "default", "delete", "do", "double", "else", "enum", 
                                      "extern", "float", "for", "goto", "if", "int", "include", "inline", 
                                      "iostream", "long", "main", "namespace", "register","return", "short", 
                                      "signed", "sizeof", "static", "std", "struct", "switch", "typedef", 
                                      "template", "typename", "try", "this" "union", "using", "unsigned", 
                                      "void", "volatile", "virtual", "while"};
    return keywords.count(token) > 0;
}

bool isOperator(const string &token){
    unordered_set<string> operators = {"+", "-", "*", "/", "%", "==", "!=", "<=", ">=", "&&", "||", "!", "=",
                                       "+=", "-=", "/=", "*=", "++", "--", "&", "|", "^", "~", "<<", ">>", "::"};

    return operators.count(token) > 0;
}

bool isConstant(const string &token){
    regex characterConstant("'.'");
    regex stringConstant("\".*\"");
    regex integerConstant("^\\d+$");
    regex floatingPointConstant("^[+-]?\\d*\\.\\d+$");

    return (regex_match(token, characterConstant) || regex_match(token, stringConstant) ||
            regex_match(token, integerConstant) || regex_match(token, floatingPointConstant));
}

int main()
{
    string filename = "sourceFile.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    string line;
    int keywordsCount = 0;
    int identifiersCount = 0;
    int operatorsCount = 0;
    int symbolsCount = 0;
    int constantsCount = 0;
    string keyarr[100];
    string idarr[100];
    string oparr[100];
    string symarr[100];
    string conarr[100];

    while (getline(inputFile, line))
    {
        istringstream inputStream(line);
        string token;

        while (inputStream >> token)
        {

            if (isKeyword(token))
            {
                keywordsCount++;
                cout << token << " is a keyword" << endl;
                // push token to array
                keyarr[keywordsCount] = token;
            }
            else if (isalpha(token[0]) || token[0] == '_')
            {
                identifiersCount++;
                cout << token << " is an identifier" << endl;
                // push token to array
                idarr[identifiersCount] = token;
            }
            else if (isOperator(token))
            {
                operatorsCount++;
                cout << token << " is an operator" << endl;
                // push token to array
                oparr[operatorsCount] = token;
            }
            else if (isConstant(token))
            {
                constantsCount++;
                cout << token << " is a constant" << endl;
                // push token to array
                conarr[constantsCount] = token;
            }
            else if (ispunct(token[0]))
            {
                symbolsCount++;
                cout << token << " is a symbol" << endl;
                // push token to array
                symarr[symbolsCount] = token;
            }
           
            cout << "Keywords: " << keywordsCount << endl;
            cout << "Identifiers: " << identifiersCount << endl;
            cout << "Operators: " << operatorsCount << endl;
            cout << "Symbols: " << symbolsCount << endl;
            cout << "Constants: " << constantsCount << endl;
            cout << " \n " << endl;
        }
    }

    inputFile.close();
    cout << "SUMMARY:" << endl;
    cout << "Keywords: " << keywordsCount << endl;
    cout << "list of keywords: ";
    // for loop for printing keyarr
    for (int i = 0; i < keywordsCount; i++)
    {
        cout << keyarr[i] << endl;
    }
    cout << " \n " << endl;

    cout << "Identifiers: " << identifiersCount << endl;
    cout << "list of identifiers: ";
    // for loop for printing idarr
    for (int i = 0; i < identifiersCount; i++)
    {
        cout << idarr[i] << endl;
    }
    cout << " \n " << endl;
    cout << "Operators: " << operatorsCount << endl;
    cout << "list of operators: ";
    // for loop for printing oparr
    for (int i = 0; i < operatorsCount; i++)
    {
        cout << oparr[i] << endl;
    }
    cout << " \n " << endl;
    cout << "Symbols: " << symbolsCount << endl;
    cout << "list of symbols: ";
    // for loop for printing symarr
    for (int i = 0; i < symbolsCount; i++)
    {
        cout << symarr[i] << endl;
    }
    cout << " \n " << endl;
    cout << "Constants: " << constantsCount << endl;
    cout << "list of constants: ";
    // for loop for printing conarr
    for (int i = 0; i < constantsCount; i++)
    {
        cout << conarr[i] << endl;
    }
    return 0;
}
