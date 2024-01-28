#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>

int main() {
    std::ifstream inputFile("C:\\Users\\preet\\Desktop\\Token.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file for reading." << std::endl;
        return 1;
    }

    std::ofstream outputFile("C:\\Users\\preet\\Desktop\\MicrosoftTeam.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file for writing." << std::endl;
        inputFile.close();
        return 1;
    }

    char character;
    bool inComment = false;
    int identifierKeywordCount = 0;
    int operatorCount = 0;
    int specialCharacterCount = 0;
    int keyword = 0;
    int variables = 0;
    int Functions_ud = 0;
    int literals = 0;
    int punctuator = 0;
    int total_tokens = 0;

    while (inputFile.get(character)) {
        if (inComment) {
            if (character == '*' && inputFile.peek() == '/') {
                inComment = false;
                inputFile.ignore(); // Ignore '/' after '*'
            }
        } else {
            if (character == '/' && inputFile.peek() == '*') {
                inComment = true;
                inputFile.ignore(); // Ignore '*' after '/'
            } else if (!std::isspace(character)) {
                // Process tokens
                if (std::isalpha(character) || character == '_') {
                    // Identifier or keyword
                    std::string token;
                    token += character;

                    while (inputFile.get(character) &&
                           (std::isalnum(character) || character == '_')) {
                        token += character;
                    }

                    inputFile.unget(); // Put back the last character
                    outputFile << "Identifier/Keyword: " << token << std::endl;
                    identifierKeywordCount++;

                    // Add logic to identify keywords
                    if (token == "if" || token == "else" || token == "while" || token == "for") {
                        keyword++;
                    } else if (std::isalpha(token[0])) {
                        // Assuming single-letter variables for simplicity
                        variables++;
                    }
                } else if (character == '+' || character == '-' || character == '*' || character == '/') {
                    // Operator
                    outputFile << "Operator: " << character << std::endl;
                    operatorCount++;
                } else if (character == ';' || character == ',' || character == '{' || character == '}' || character == '(' || character == ')') {
                    // Special character
                    outputFile << "Special Character: " << character << std::endl;
                    specialCharacterCount++;
                    punctuator++;
                } else if (character == '\"') {
                    // Literal
                    std::string literal;
                    literal += character;
                    while (inputFile.get(character) && character != '\"') {
                        literal += character;
                    }
                    literal += character; // Include the closing quote
                    outputFile << "Literal: " << literal << std::endl;
                    literals++;
                }
                total_tokens++;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File processed successfully." << std::endl;
    std::cout << "Identifier/Keyword Count: " << identifierKeywordCount << std::endl;
    std::cout << "Operator Count: " << operatorCount << std::endl;
    std::cout << "Special Character Count: " << specialCharacterCount << std::endl;

    printf("Total no of Keywords: %d\n", keyword);
    printf("Total no of Variables: %d\n", variables);
    printf("Total no of User Defined Functions: %d\n", Functions_ud);
    printf("Total no of Literals: %d\n", literals);
    printf("Total no of Punctuators: %d\n", punctuator);
    printf("Total no of Operators: %d\n", operatorCount);
    printf("Total number of tokens: %d\n", total_tokens);

    return 0;
}
