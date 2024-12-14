//
// Created by hasil on 12/13/2024.
//

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
private:
    int id = 0;  // Unique patient ID
    std::string first_name;
    std::string last_name;
    std::string date_of_birth;
    std::string blood_type;
    std::string diagnosis;
    std::string date_of_admission;
    std::string date_of_discharge;
    long int doctor_id = 0;  // Associated doctor's ID

public:
    // Default constructor
    Patient();

    // Parameterized constructor
    Patient(int id, const std::string& first_name, const std::string& last_name, const std::string& date_of_birth,
            const std::string& blood_type, const std::string& diagnosis, const std::string& date_of_admission,
            const std::string& date_of_discharge, long int doctor_id);

    // Getters
    int get_id() const;
    const std::string& get_first_name() const;
    const std::string& get_last_name() const;
    const std::string& get_date_of_birth() const;
    const std::string& get_blood_type() const;
    const std::string& get_diagnosis() const;
    const std::string& get_date_of_admission() const;
    const std::string& get_date_of_discharge() const;
    long int get_doctor_id() const;

    // Setters
    void set_id(int new_id);
    void set_first_name(const std::string& new_first_name);
    void set_last_name(const std::string& new_last_name);
    void set_date_of_birth(const std::string& new_date_of_birth);
    void set_blood_type(const std::string& new_blood_type);
    void set_diagnosis(const std::string& new_diagnosis);
    void set_date_of_admission(const std::string& new_date_of_admission);
    void set_date_of_discharge(const std::string& new_date_of_discharge);
    void set_doctor_id(long int new_doctor_id);

    // Utility
    std::string toString() const;
};

#endif // PATIENT_H