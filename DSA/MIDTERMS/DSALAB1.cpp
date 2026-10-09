#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

struct Student {
    int idNumber;
    string name;
};

class StudentsRecord {
private:
    list<Student> students;

    static bool readNumber(const string& prompt, int& number) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return false;

        istringstream input(line);
        char extra;
        if (!(input >> number) || (input >> extra) || number <= 0) {
            cout << "Please enter a positive whole number.\n";
            return false;
        }
        return true;
    }

    static bool readName(const string& prompt, string& name) {
        cout << prompt;
        if (!getline(cin, name)) return false;
        if (name.find_first_not_of(" \t\r") == string::npos) {
            cout << "Name cannot be empty.\n";
            return false;
        }
        return true;
    }

    list<Student>::iterator findStudent(int idNumber) {
        return find_if(students.begin(), students.end(), [idNumber](const Student& student) {
            return student.idNumber == idNumber;
        });
    }

    void addStudent() {
        Student student;
        if (!readName("Enter the name of student: ", student.name) ||
            !readNumber("ID number: ", student.idNumber)) return;
        if (findStudent(student.idNumber) != students.end()) {
            cout << "A student with that ID already exists.\n";
            return;
        }
        students.push_back(student);
        cout << "Student added.\n";
    }

    void removeStudent() {
        int idNumber;
        if (!readNumber("ID number to remove: ", idNumber)) return;
        auto student = findStudent(idNumber);
        if (student == students.end()) {
            cout << "Student not found.\n";
            return;
        }
        students.erase(student);
        cout << "Student removed.\n";
    }

    void searchStudent() {
        int idNumber;
        if (!readNumber("ID number to search: ", idNumber)) return;
        auto student = findStudent(idNumber);
        if (student == students.end()) {
            cout << "Student not found.\n";
            return;
        }
        cout << "ID: " << student->idNumber << " | Name: " << student->name << '\n';
    }

    void updateStudent() {
        int idNumber;
        if (!readNumber("ID number to update: ", idNumber)) return;
        auto student = findStudent(idNumber);
        if (student == students.end()) {
            cout << "Student not found.\n";
            return;
        }

        string newName;
        int newIdNumber;
        if (!readName("New name: ", newName) ||
            !readNumber("New ID number: ", newIdNumber)) return;
        if (newIdNumber != idNumber && findStudent(newIdNumber) != students.end()) {
            cout << "A student with that ID already exists.\n";
            return;
        }
        student->name = newName;
        student->idNumber = newIdNumber;
        cout << "Student updated.\n";
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }
        for (const Student& student : students) {
            cout << "ID: " << student.idNumber << " | Name: " << student.name << '\n';
        }
    }

public:
    void run() {
        cout << "---------- Student Record Manager ----------\n";
        while (true) {
            cout << "\nStudent Record Menu\n"
                 << "1. Add student\n"
                 << "2. Remove student\n"
                 << "3. Search student\n"
                 << "4. Total students\n"
                 << "5. Update student\n"
                 << "6. Display students\n"
                 << "7. Exit\n";

            int option;
            if (!readNumber("Choose an option: ", option)) {
                if (!cin) break;
                continue;
            }

            switch (option) {
                case 1: addStudent(); break;
                case 2: removeStudent(); break;
                case 3: searchStudent(); break;
                case 4: cout << "Total students: " << students.size() << '\n'; break;
                case 5: updateStudent(); break;
                case 6: displayStudents(); break;
                case 7: return;
                default: cout << "Invalid option. Please choose 1-7.\n";
            }
        }
    }
};

int main() {
    StudentsRecord record;
    record.run();
    return 0;
}
