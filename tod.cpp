#include <iostream>
#include <vector>
#include <string>

class Patient {
    int patientID;
    std::string name;
    std::string contactNumber;
public:
    Patient(int id, const std::string& n, const std::string& contact) : patientID(id), name(n), contactNumber(contact) {}

    int getID() const {
        return patientID;
    }

    std::string getName() const {
        return name;
    }

    std::string getContactNumber() const {
        return contactNumber;
    }
};

class Doctor {
    int doctorID;
    std::string name;
    std::string specialization;
public:
    Doctor(int id, const std::string& n, const std::string& spec) : doctorID(id), name(n), specialization(spec) {}

    int getID() const {
        return doctorID;
    }

    std::string getName() const {
        return name;
    }

    std::string getSpecialization() const {
        return specialization;
    }
};

class Hospital {
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
public:
    void addPatient(int id, const std::string& name, const std::string& contact) {
        Patient newPatient(id, name, contact);
        patients.push_back(newPatient);
        std::cout << "Patient added successfully!" << std::endl;
    }

    void addDoctor(int id, const std::string& name, const std::string& spec) {
        Doctor newDoctor(id, name, spec);
        doctors.push_back(newDoctor);
        std::cout << "Doctor added successfully!" << std::endl;
    }

    Patient* findPatient(int id) {
        for (auto& patient : patients) {
            if (patient.getID() == id) {
                return &patient;
            }
        }

        return nullptr;
    }

    Doctor* findDoctor(int id) {
        for (auto& doctor : doctors) {
            if (doctor.getID() == id) {
                return &doctor;
            }
        }

        return nullptr;
    }
};

int main() {
    Hospital hospital;

    hospital.addPatient(1, "stephen Owusu", "02011331");
    hospital.addPatient(2, "Efo Kumi", "001244421");

    hospital.addDoctor(101, "Dr. Adomah", "optometry");
    hospital.addDoctor(102, "Dr. Emma", "Cardiology");

    Patient* patient1 = hospital.findPatient(1);
    if (patient1) {
        std::cout << "Patient ID: " << patient1->getID() << ", Name: " << patient1->getName() << ", Contact: " << patient1->getContactNumber() << std::endl;
    } else {
        std::cout << "Patient not found!" << std::endl;
    }

    Doctor* doctor1 = hospital.findDoctor(101);
    if (doctor1) {
        std::cout << "Doctor ID: " << doctor1->getID() << ", Name: " << doctor1->getName() << ", Specialization: " << doctor1->getSpecialization() << std::endl;
    } else {
        std::cout << "Doctor not found!" << std::endl;
    }

    return 0;
}