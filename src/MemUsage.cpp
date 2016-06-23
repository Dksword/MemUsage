//============================================================================
// Name        : MemUsage.cpp
// Author      : Frank
// Email        : zhang.flyer@163.com
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int parseLine(std::string& line) {
	return std::atoi(line.substr(line.find_first_not_of(" ", 6), line.find_last_of(" ")).c_str());
}

int getMemUsage() {
	int result = -1;
	char *filename="/proc/self/status";
	std::ifstream fp(filename);
	if (!fp.is_open()) {
		std::cerr << "Can not open file: " << filename << std::endl;
		exit(-1);
	}
	std::string line;
	while (!fp.eof()) {
		std::getline(fp, line);
		if (line.length() && !line.compare(0, 6, "VmRSS:")) {
			result = parseLine(line);
			break;
		}
	}
	fp.close();
	return result;
}

int main() {

	float result = getMemUsage();

	cout<< "Memory Usage by Current Process is : " << result << "KB" << endl;

	return 0;
}
