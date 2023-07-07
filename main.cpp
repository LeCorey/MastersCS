
//

#include <iostream>

const int NUM_MONTHS = 12;
const int MIN_TEMP = -100;
const int MAX_TEMP = 140;

struct WeatherData {
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
    
};

void inputData(WeatherData& data, int month) {
    std::cout << "Enter weather data for the Month" << month + 1 << ":\n";
    
    std::cout <<"Total rainfall: ";
    std::cin >> data.totalRainfall;
    
    std::cout <<"High Temperature: ";
    std::cin >> data.highTemperature;
    
    std::cout << "Low temperature: ";
    std::cin >> data.lowTemperature;
    
    
    data.averageTemperature = (data.highTemperature + data.lowTemperature) / 2;
    
}

void validateTemperature(double& temperature) {
    while (temperature < MIN_TEMP || temperature > MAX_TEMP) {
        std::cout << "Temperature must beb between -100 and 140 degrees F. Please re-enter: ";
        std::cin >> temperature;
        
    }
}

void calculateStatistics(WeatherData data[], double& averageMonthlyRainfall, double& totalYearlyRainfall, double& highestTemperature, int& highestTemperatureMonth, double& lowestTemperature, int& lowestTemperatureMonth, double& averageTemperature) {
    
    averageMonthlyRainfall = 0.0;
    totalYearlyRainfall = 0.0;
    highestTemperature = data[0].highTemperature;
    highestTemperatureMonth = 0;
    lowestTemperature = data[0].lowTemperature;
    lowestTemperatureMonth = 0;
    averageTemperature = 0.0;
    
    for (int i = 0; i < NUM_MONTHS; i++) {
        averageMonthlyRainfall += data[i].totalRainfall;
        totalYearlyRainfall += data[i].totalRainfall;
        averageTemperature += data[i].averageTemperature;
        
        if (data[i].highTemperature > highestTemperature){
            highestTemperature = data[i].highTemperature;
            highestTemperatureMonth = i;
            
        }
        
        if (data[i].lowTemperature < lowestTemperature) {
            lowestTemperature = data[i].lowTemperature;
            lowestTemperatureMonth = i;
        }
    }
    
    averageMonthlyRainfall /= NUM_MONTHS;
    averageTemperature /= NUM_MONTHS;
}

int main() {
    WeatherData monthlyData[NUM_MONTHS];
    double averageMonthlyRainfall, totalYearlyRainfall, highestTemperature, lowestTemperature, averageTemperature;
    int highestTemperatureMonth, lowestTemperatureMonth;
    
    for (int i = 0; i < NUM_MONTHS; i++) {
        inputData(monthlyData[i], i);
        
    }
    
    calculateStatistics(monthlyData, averageMonthlyRainfall, totalYearlyRainfall, highestTemperature, highestTemperatureMonth, lowestTemperature, lowestTemperatureMonth, averageTemperature);
    
    std::cout << "\nYearly Weather Stats: \n";
    std::cout << "Average monthly rainfall: " <<averageMonthlyRainfall << "\n";
    std::cout << "Total Rain for the year: " << totalYearlyRainfall << "\n";
    std::cout << "Highest Temp: " << highestTemperature << " (Month " << highestTemperatureMonth + 1 << ")\n";
    std::cout << "Lowest Temp: " << lowestTemperature << " (Month " << lowestTemperatureMonth + 1 << ")\n";
    std::cout << "Average of Monthly Average Temps: " << averageTemperature << std::endl;
    
    return 0;
}
