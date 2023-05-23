//
//  main.cpp
//  Homework 7

#include <iostream>
#include <vector>

int main() {

    std::vector<int> luckyNumbers = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    
    int winningNumber;
    std::cout << "Enter this week's 5-digit winning lottery numbers: ";
    std::cin >> winningNumber;
    
    bool isWinner = false;
    int i = 0;
    while (i < luckyNumbers.size()) {
        if (luckyNumbers[i] == winningNumber) {
            isWinner = true;
            break;
        }
        i++;
    }
    
    if (isWinner) {
        std::cout << "WINNER!! BIG MONEY$$$$$$" << std::endl;
    } else {
        std::cout << "You did not win this week." << std::endl;
    }
    
    return 0;
}

    

