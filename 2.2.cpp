
//

#include <iostream>
#include <cctype>

bool isPasswordValid(const std::string& password) {
    //Length of Password
    if (password.length() <6) {
        std::cout << "Password should be at least six characters long." << std::endl;
        return false;
        
    }
    
    //Password must have at least one uppercase letter
    bool hasUppercase = false;
    //Password must have at lease one lowercase letter
    bool hasLowercase = false;
    //Password must have at lease one number
    bool hasDigit = false;
    
    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUppercase = true;
        } else if (std::islower(ch)) {
            hasLowercase = true;
        } else if (std::isdigit(ch)) {
            hasDigit = true;
        }
        
    }
    
    //Check password input
    if (!hasUppercase) {
        std::cout << "Password should have at least one uppercase letter." << std::endl;
    }
    if (!hasLowercase) {
        std::cout << "Password should have at least one lowercase letter." << std::endl;
    }
    if (!hasDigit) {
        std::cout << "Password should have at least one number." <<std::endl;
        
    }
    
    //True if all requirements are met
    return (hasUppercase && hasLowercase && hasDigit);
}

int main() {
    std::string password;
    std::cout <<"Enter your password: ";
    std::cin >> password;
    
    if (isPasswordValid(password)) {
        std::cout <<"Password is valid." << std::endl;
    }
    
    return 0;
    
}
