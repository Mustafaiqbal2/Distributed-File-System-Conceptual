#include "taskManagementSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

std::string readEntireFile(const std::string& fileName) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error opening file: " << fileName << std::endl;
		return "";
	}

	std::ostringstream contentStream;
	std::string line;

	// Read the file line by line
	while (std::getline(file, line)) {
		// Append the line to the string
		contentStream << line << '\n';
	}

	// Close the file
	file.close();

	// Get the content from the stringstream
	std::string content = contentStream.str();

	return content;
}
