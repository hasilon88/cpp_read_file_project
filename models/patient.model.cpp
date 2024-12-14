// Created by hasil on 12/13/2024.

#include "patient.model.h"
#include <iostream>
#include <sstream>

using namespace std;

static int global_id = 0;

Patient::Patient() {
    id = ++global_id;
    first_name = "";
    last_name = "";
    date_of_birth = "";
    blood_type = "";
    diagnosis = "";
    date_of_admission = "";
    date_of_discharge = "";
    doctor_id = 0;
}

Patient::Patient(int id, const string& first_name, const string& last_name, const string& date_of_birth,
                 const string& blood_type, const string& diagnosis, const string& date_of_admission,
                 const string& date_of_discharge, long int doctor_id)
    : id(id), first_name(first_name), last_name(last_name), date_of_birth(date_of_birth),
      blood_type(blood_type), diagnosis(diagnosis), date_of_admission(date_of_admission),
      date_of_discharge(date_of_discharge), doctor_id(doctor_id) {
}

int Patient::get_id() const {
    return id;
}

const string& Patient::get_first_name() const {
    return first_name;
}

const string& Patient::get_last_name() const {
    return last_name;
}

const string& Patient::get_date_of_birth() const {
    return date_of_birth;
}

const string& Patient::get_blood_type() const {
    return blood_type;
}

const string& Patient::get_diagnosis() const {
    return diagnosis;
}

const string& Patient::get_date_of_admission() const {
    return date_of_admission;
}

const string& Patient::get_date_of_discharge() const {
    return date_of_discharge;
}

long int Patient::get_doctor_id() const {
    return doctor_id;
}

void Patient::set_id(int new_id) {
    id = new_id;
}

void Patient::set_first_name(const string& new_first_name) {
    first_name = new_first_name;
}

void Patient::set_last_name(const string& new_last_name) {
    last_name = new_last_name;
}

void Patient::set_date_of_birth(const string& new_date_of_birth) {
    date_of_birth = new_date_of_birth;
}

void Patient::set_blood_type(const string& new_blood_type) {
    blood_type = new_blood_type;
}

void Patient::set_diagnosis(const string& new_diagnosis) {
    diagnosis = new_diagnosis;
}

void Patient::set_date_of_admission(const string& new_date_of_admission) {
    date_of_admission = new_date_of_admission;
}

void Patient::set_date_of_discharge(const string& new_date_of_discharge) {
    date_of_discharge = new_date_of_discharge;
}

void Patient::set_doctor_id(long int new_doctor_id) {
    doctor_id = new_doctor_id;
}

string Patient::toString() const {
    stringstream ss;
    ss << "Patient Details:" << endl;
    ss << "ID: " << id << endl;
    ss << "First Name: " << first_name << endl;
    ss << "Last Name: " << last_name << endl;
    ss << "Date of Birth: " << date_of_birth << endl;
    ss << "Blood Type: " << blood_type << endl;
    ss << "Diagnosis: " << diagnosis << endl;
    ss << "Date of Admission: " << date_of_admission << endl;
    ss << "Date of Discharge: " << date_of_discharge << endl;
    ss << "Doctor ID: " << doctor_id << endl;

    return ss.str();
}
