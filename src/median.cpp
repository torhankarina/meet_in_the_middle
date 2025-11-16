#include <iostream>
#include "median.hpp"
#include <fstream>
#include <sstream>

double computeMedian(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return 0;
    }

    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "File is empty.\n";
        return 0;
    }

    int count = 1;
    for (char c : line) {
        if (c == ',') count++;
    }

    int* data = new int[count];

    std::stringstream ss(line);
    std::string temp;
    int index = 0;

    while (std::getline(ss, temp, ',')) {
        data[index] = std::stoi(temp);
        index++;
    }

    double median = 0.0;

    if (count % 2 == 1) {
        median = data[count / 2];
    } else {
        int mid1 = data[(count / 2) - 1];
        int mid2 = data[count / 2];
        median = (mid1 + mid2) / 2.0;
    }

    delete[] data;

    return median;
}
