#include <iostream>
#include <fstream>
#include <string>

int main() {
    int pos;
    std::ifstream file("Subject.txt");
    
    // Check if file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open Subject.txt" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        std::string lowerLine = line;
        for (char& c : lowerLine) {
            c = std::tolower(c);
        }
        pos = line.find("love");
        if (pos >= line.length()) {
            std::cout << "'love' not found in the line." << std::endl;
        } else {
            std::cout << "'love' found at position: " << pos << std::endl;
        }
    }
    
    file.close();
    return 0;
}