//txt file with data, read character by character and copy it to another file in the same code

#include <iostream>
#include <fstream>
#include <cctype> // For std::isspace

int main() {
    // Open the source file for reading
    std::ifstream inputFile("C:\\Users\\preet\\Desktop\\AdobeTeam.txt");

    // Check if the source file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file for reading." << std::endl;
        return 1;
    }

    // Open the destination file for writing
    std::ofstream outputFile("C:\\Users\\preet\\Desktop\\MicrosoftTeam.txt");

    // Check if the destination file opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file for writing." << std::endl;
        inputFile.close(); // Close the source file before returning
        return 1;
    }

    // Read characters from the source file, copy to the destination file, and count tokens
    char character;
    int tokenCount = 0;
    bool inToken = false;

    while (inputFile.get(character)) {
        // Copy character to the destination file
        outputFile.put(character);

        // Count tokens based on whitespace
        if (std::isspace(character)) {
            if (inToken) {
                inToken = false;
                tokenCount++;
            }
        } else {
            inToken = true;
        }
    }

    // If the last character is not whitespace, consider it as the end of the last token
    if (inToken) {
        tokenCount++;
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully." << std::endl;
    std::cout << "Number of tokens in the file: " << tokenCount << std::endl;

    return 0;
}
