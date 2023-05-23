//
//  main.cpp
//  Homework 6
//
//  Created by LeCorey Johnson on 5/3/23.
//

#include <iostream>
#include <string>

int main() {
    const int numMonths = 12;
    std::string months[numMonths] = {"January", "February", "March", "April", "May", "June",
                                     "July", "August", "September", "October", "November", "December"};
    double rainfall[numMonths];
    double totalRainfall = 0.0;
    double averageRainfall;
    double maxRainfall = 0.0;
    double minRainfall = std::numeric_limits<double>::max();
    std::string monthWithMaxRainfall, monthWithMinRainfall;

    // Input validation loop
    for (int i = 0; i < numMonths; ++i) {
        bool validInput = false;
        while (!validInput) {
            std::cout << "Enter rainfall for " << months[i] << ": ";
            if (std::cin >> rainfall[i] && rainfall[i] >= 0) {
                validInput = true;
            } else {
                std::cout << "Invalid input. Rainfall cannot be negative. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        totalRainfall += rainfall[i];

        if (rainfall[i] > maxRainfall) {
            maxRainfall = rainfall[i];
            monthWithMaxRainfall = months[i];
        }

        if (rainfall[i] < minRainfall) {
            minRainfall = rainfall[i];
            monthWithMinRainfall = months[i];
        }
    }

    averageRainfall = totalRainfall / numMonths;

    std::cout << "Total rainfall: " << totalRainfall << std::endl;
    std::cout << "Average rainfall: " << averageRainfall << std::endl;
    std::cout << "Least rainfall in: " << monthWithMinRainfall << std::endl;
    std::cout << "Most rainfall in: " << monthWithMaxRainfall << std::endl;

    return 0;
}
