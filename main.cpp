//
//  main.cpp
//  ProgrammingProject2
//
//  Created by LeCorey Johnson on 9/8/23.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

class Shooter {
private:
    string name;
    int bulletCount;
    int initialBulletCount;

public:
    Shooter(string name, int bullet) : name(name), bulletCount(bullet), initialBulletCount(bullet) {}

    void shooting() {
        if (bulletCount > 0) {
            bulletCount--;
        }
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return bulletCount;
    }

    void display() {
        cout << "Shooter's Name: " << name << ", Remaining Bullets: " << bulletCount << endl;
    }

    bool isComplete() {
        return bulletCount == 0;
    }

    void reload() {
        bulletCount = initialBulletCount;
    }
};

int main() {
    queue<Shooter> shootingRange;

    ifstream inputFile("Week3-bulletCount.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read shooter information from the file and create shooter objects
    string name;
    int bulletCount;
    while (inputFile >> name >> bulletCount) {
        Shooter shooter(name, bulletCount);
        shootingRange.push(shooter);
        
        // Display status information
        cout << "Shooter: " << shooter.getName() << " added to the queue. Remaining Bullets: " << shooter.getQuantity() << endl;
    }

    inputFile.close();

    while (!shootingRange.empty()) {
        Shooter shooter = shootingRange.front();
        shootingRange.pop();

        shooter.shooting();

        if (shooter.isComplete()) {
            cout << "Shooter with Name=" << shooter.getName() << " is completed." << endl;
        } else {
            cout << "Shooter with Name=" << shooter.getName() << " needs to shoot " << shooter.getQuantity() << " more bullets." << endl;
            shootingRange.push(shooter);
            cout << "Shooter Name=" << shooter.getName() << " is sent back to the queue. Remaining bullets: " << shooter.getQuantity() << endl;
        }
    }

    return 0;
}
