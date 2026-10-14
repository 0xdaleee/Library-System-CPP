#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <string>

using namespace std;

class StudentsRecord {
private:
    struct Student {
        int idNumber;
        string name;
        double grade;
    };

    list<Student> students;

    list<Student>::iterator findStudent(int idNumber) {
        for (auto student = students.begin(); student != students.end(); ++student) {
            if (student->idNumber == idNumber) {
                return student;
            }
        }
        return students.end();
    }

    int readInt(const string& prompt) {
        int value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }

    double readGrade() {
        double grade;
        while (true) {
            cout << "Enter Grade (0-100): ";
            if (cin >> grade && grade >= 0 && grade <= 100) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return grade;
            }

            cout << "Invalid grade. Enter a number from 0 to 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void displayStudent(const Student& student) const {
        cout << left << setw(10) << student.idNumber
             << setw(25) << student.name
             << fixed << setprecision(2) << student.grade << '\n';
    }

    void addStudent() {
        Student student;
        student.idNumber = readInt("Enter student ID: ");

        if (findStudent(student.idNumber) != students.end()) {
            cout << "Error: Student ID already exists.\n";
            return;
        }

        cout << "Enter student name: ";
        getline(cin, student.name);
        if (student.name.empty()) {
            cout << "Error: Name cannot be empty.\n";
            return;
        }

        student.grade = readGrade();
        students.push_back(student);
        cout << "Student added successfully.\n";
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }

        cout << left << setw(10) << "ID" << setw(25) << "Name" << "Grade\n";
        cout << string(45, '-') << '\n';
        for (const Student& student : students) {
            displayStudent(student);
        }
    }

    void searchStudent() {
        int idNumber = readInt("Enter student ID to search: ");
        auto student = findStudent(idNumber);

        if (student == students.end()) {
            cout << "Student not found.\n";
            return;
        }

        cout << "Student found:\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << "Grade\n";
        displayStudent(*student);
    }

    void removeStudent() {
        int idNumber = readInt("Enter student ID to remove: ");
        auto student = findStudent(idNumber);

        if (student == students.end()) {
            cout << "Student not found.\n";
            return;
        }

        students.erase(student);
        cout << "Student removed successfully.\n";
    }

    void updateStudent() {
        int idNumber = readInt("Enter student ID to update: ");
        auto student = findStudent(idNumber);

        if (student == students.end()) {
            cout << "Student not found.\n";
            return;
        }

        cout << "Enter new student name: ";
        string newName;
        getline(cin, newName);
        if (newName.empty()) {
            cout << "Name cannot be empty. Update cancelled.\n";
            return;
        }

        double newGrade = readGrade();
        student->name = newName;
        student->grade = newGrade;
        cout << "Student updated successfully.\n";
    }

    void sortStudents() {
        students.sort([](const Student& first, const Student& second) {
            return first.grade < second.grade;
        });
        cout << "Students sorted by grade in ascending order.\n";
    }

    void showHighestAndLowestGrade() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }

        double highest = students.front().grade;
        double lowest = students.front().grade;
        for (const Student& student : students) {
            if (student.grade > highest) highest = student.grade;
            if (student.grade < lowest) lowest = student.grade;
        }

        cout << "Highest grade: " << highest << '\n';
        for (const Student& student : students) {
            if (student.grade == highest) displayStudent(student);
        }

        cout << "Lowest grade: " << lowest << '\n';
        for (const Student& student : students) {
            if (student.grade == lowest) displayStudent(student);
        }
    }

public:
    void mainMenu() {
        int userChoice;
        do {
            cout << "\n===== STUDENT RECORD MANAGER =====\n"
                 << "1. Add Student\n"
                 << "2. Display All Students\n"
                 << "3. Search Student\n"
                 << "4. Remove Student\n"
                 << "5. Update Student\n"
                 << "6. Sort Students (Ascending)\n"
                 << "7. Show Highest and Lowest Grades\n"
                 << "8. Count Students\n"
                 << "0. Exit\n";

            userChoice = readInt("Enter your choice: ");
            switch (userChoice) {
                case 1: addStudent(); break;
                case 2: displayAllStudents(); break;
                case 3: searchStudent(); break;
                case 4: removeStudent(); break;
                case 5: updateStudent(); break;
                case 6: sortStudents(); break;
                case 7: showHighestAndLowestGrade(); break;
                case 8: cout << "Total students: " << students.size() << '\n'; break;
                case 0: cout << "Exiting program.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (userChoice != 0);
    }
};

int main() {
    StudentsRecord record;
    record.mainMenu();
    return 0;
}
