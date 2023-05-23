#include <iostream>
using namespace std;

bool isValid(double x) { return x >= 0.0; }
void selectionSortArray(double [], int elems, string []);

double getValidRain(string month) {
	double rain;
	cout << "Enter rainfall for " << month << ": ";
	cin >> rain;
	while (!isValid(rain)) {
		cout << "invalid data (negative rainfall) -- retry";
		cin >> rain;
	}
	return rain;
}

double sumArray(double x[], int n) {
	double sum = 0.0;
	for (int k = 0; k < n; k++)
		sum += x[k];
	return sum;
}

// assumes n>0
int findMaxArray(double x[], int n) {
	int max = 0;
	for (int k = 1; k < n; k++)
		if (x[max] < x[k]) max = k;
	return max;
}

// assumes n>0
int findMinArray(double x[], int n) {
	int min = 0;
	for (int k = 1; k < n; k++)
		if (x[min] > x[k]) min = k;
	return min;
}

int main() {
	const int MONTHS = 12;
	string monthNames[MONTHS] = { "January", "February", "March", "April",
				"May", "June", "July", "August", "September",
				"October", "November", "December" };
	double	rainfall[MONTHS];

	for (int m = 0; m < MONTHS; m++)
		rainfall[m] = getValidRain(monthNames[m]);

	double total = sumArray(rainfall, MONTHS);

	cout << "Total rainfall: " << total << endl;
	cout << "Average rainfall: " << total / MONTHS << endl;
	cout << "Least rainfall in: " << monthNames[findMinArray(rainfall, MONTHS)] << endl;
	cout << "Most rainfall in: " << monthNames[findMaxArray(rainfall, MONTHS)] << endl;

	selectionSortArray(rainfall, MONTHS, monthNames);

	for (int i = 0; i < MONTHS; i++)
	{
		cout << rainfall[i] << " inches in " << monthNames[i] << endl;
	}


	return 0;
}

void selectionSortArray(double array[], int elems, string monthNames[])
{
	int seek; // array position currently being put in order 
	int minCount; // location of smallest value found
	double minValue; // holds the smallest value found

	for (seek = 0; seek < (elems - 1); seek++) // outer loop performs the swap
	// and then increments seek
	{
		minCount = seek;
		minValue = array[seek];
		for (int index = seek + 1; index < elems; index++)
		{
			// inner loop searches through array
			// starting at array[seek] searching
			// for the smallest value. When the
			// value is found, the subscript is
			// stored in minCount. The value is
			// stored in minValue.
			if (array[index] < minValue)
			{
				minValue = array[index];
				minCount = index;
			}
		}
		// the following two statements exchange the value of the
		// element currently needing the smallest value found in the
		// pass(indicated by seek) with the smallest value found
		// (located in minValue)

		array[minCount] = array[seek];
		array[seek] = minValue;
		swap(monthNames[minCount], monthNames[seek]);
	}
}
		