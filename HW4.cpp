//
//  main.cpp
//  HW4
// Chapter 5, Programming Challenge 25: Using Files-Student Line Up
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string name;        // To hold a student's name
    string front;        // To hold the least alphabetic value
    string back;        // To hold the greatest alphabetic value
    ifstream inFile;    // To hold the input file

    // Open the file.
    inFile.open("LineUp.txt");
    if (!inFile) {
        cout << "File not found!";
    }
    else {
        // Read the first student's name from the file.
        inFile >> name;

        // Set front and back equal to the first student's name.
        front = name;
        back = name;

        // Read the remaining student's names from the file.
        while (inFile >> name)
        {
            

            // Determine if this name is least.
            if (name < front)
                front = name;

            // Determine if this name is the greatest.
            if (name > back)
                back = name;
        }

        // Close the file.
        inFile.close();

        // Display the name of the student who is in the
        // front of the line.
        cout << front << " is in the front.\n";

        // Display the name of the student who is in the
        // back of the line.
        cout << back << " is in the back.\n\n";




    }



    return 0;
}
