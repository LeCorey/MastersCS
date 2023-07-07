#include <iostream>
using namespace std;

double totalCharges(int days, double rate, double meds, double services) {
    if (days < 0 || rate < 0 || meds < 0 || services < 0) {
        return -1;
    }
    return days * rate + meds + services;
}

double totalCharges(double services, double meds) {
    if (services < 0 || meds < 0) {
        return -1;
    }
    return services + meds;
}

int main() {
    char patientType;
    int days;
    double rate, meds, services;

    cout << "Was the patient an inpatient (I) or an outpatient (O)? ";
    cin >> patientType;

    if (patientType == 'I') {
        cout << "Number of days spent in the hospital: ";
        cin >> days;
        cout << "Daily rate: ";
        cin >> rate;
        cout << "Hospital medication charges: ";
        cin >> meds;
        cout << "Charges for hospital services (lab tests, etc.): ";
        cin >> services;
        cout << "Total charges: $" << totalCharges(days, rate, meds, services) << endl;
    }
    else if (patientType == 'O') {
        cout << "Charges for hospital services (lab tests, etc.): ";
        cin >> services;
        cout << "Hospital medication charges: ";
        cin >> meds;
        cout << "Total charges: $" << totalCharges(services, meds) << endl;
    }
    else {
        cout << "Invalid patient type." << endl;
    }

    return 0;
}
