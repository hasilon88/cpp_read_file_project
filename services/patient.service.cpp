#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "../models/patient.model.h"

using namespace std;

vector<string> readFileLines(const string& fileName) {
    vector<string> lines;
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return lines;
    }

    string line;
    int counter = 0;
    while (getline(file, line)) {
        counter++;

        if (counter == 1) {
            continue;
        }

        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    file.close();
    return lines;
}

vector<string> split(const string& s, const char delim) {
    vector<string> splitResult;
    string tempWord = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == delim) {
            if (!tempWord.empty()) {
                splitResult.push_back(tempWord);
                tempWord = "";
            }
        } else {
            tempWord += s[i];
        }
    }

    if (!tempWord.empty()) {
        splitResult.push_back(tempWord);
    }

    return splitResult;
}

int safeStoi(const string& str) {
    try {
        for (char c : str) {
            if (!isdigit(c)) {
                throw invalid_argument("Non-numeric character found.");
            }
        }
        return stoi(str);
    } catch (const invalid_argument& e) {
        cout << "Error converting string to int: " << str << endl;
        return 0;
    }
}

Patient mapLineToPatient(const string& line) {
    const vector<string> patientInfo = split(line, ',');

    if (patientInfo.size() < 9) {
        cout << "Error: Incomplete patient data." << endl;
        return Patient();
    }

    string doctorId = patientInfo[3] == "none" ? "" : patientInfo[3];
    string dischargeDate = patientInfo[8] == "none" ? "" : patientInfo[8];

    return Patient(
        safeStoi(patientInfo[2]),  // Patient ID
        patientInfo[0],            // First Name
        patientInfo[1],            // Last Name
        patientInfo[4],            // Date of Birth (stored as an integer YYYYMMDD)
        patientInfo[5],            // Blood Type
        patientInfo[6],            // Diagnosis
        patientInfo[7],            // Admission Date (stored as an integer YYYYMMDD)
        dischargeDate,             // Discharge Date
        safeStoi(doctorId)         // Doctor ID (optional, empty if "none")
    );
}

vector<Patient> fetchAllPatients() {
    vector<Patient> patients;
    vector<string> allPatientsInfo = readFileLines("C:\\Users\\hasil\\CLionProjects\\final\\services\\patients.txt");

    for (int i = 0; i < allPatientsInfo.size(); ++i) {
        patients.push_back(mapLineToPatient(allPatientsInfo[i]));
    }

    return patients;
}

int main() {
    vector<Patient> patients = fetchAllPatients();

    system("cls");
    for (int i = 0; i < patients.size(); ++i) {
        cout << patients[i].toString() << endl;

        for (int j = 0; j < 50; j++) {
            cout << "-";
        }
        cout << endl;
    }

    return 0;
}
