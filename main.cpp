#include <iostream>
#include <fstream>
#include "src/median.hpp"

int main() {
    std::string filename;

    std::cout << "Enter the filename: ";
    std::cin >> filename;

    double median = computeMedian(filename);

    std::cout << "The median of the dataset is " << median << std::endl;

    return 0;
}