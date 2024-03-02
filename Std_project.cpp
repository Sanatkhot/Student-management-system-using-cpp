#include <iostream>
#include <vector>

class Student {
public:
    // Student objec
    Student(int id, const std::string& name, int age)
        : studentId(id), studentName(name), studentAge(age) {}

    // student details
    void displayDetails() const {
        std::cout << "Student ID: " << studentId << "\tName: " << studentName << "\tAge: " << studentAge << std::endl;
    }

    // student ID
    int getId() const {
        return studentId;
    }

private:
    int studentId;
    std::string studentName;
    int studentAge;
};

class StudentManagementSystem {
public:
    //  add a new student
    void addStudent(int id, const std::string& name, int age) {
        Student newStudent(id, name, age);
        students.push_back(newStudent);
        std::cout << "Student added successfully!" << std::endl;
    }

    // display all students
    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "No students available." << std::endl;
        } else {
            std::cout << "Student List:\n";
            for (const auto& student : students) {
                student.displayDetails();
            }
        }
    }

    // search a ID
    void searchStudentById(int id) const {
        for (const auto& student : students) {
            if (student.getId() == id) {
                std::cout << "Student found:\n";
                student.displayDetails();
                return;
            }
        }
        std::cout << "Student not found with ID: " << id << std::endl;
    }

private:
    std::vector<Student> students;
};

int main() {
    StudentManagementSystem studentSystem;
    int choice, id, age;
    std::string name;

    do {
        std::cout << "\nStudent Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cout << "Enter student name: ";
                std::cin.ignore(); 
                std::getline(std::cin, name);
                std::cout << "Enter student age: ";
                std::cin >> age;
                studentSystem.addStudent(id, name, age);
                break;
            case 2:
                studentSystem.displayAllStudents();
                break;
            case 3:
                std::cout << "Enter student ID to search: ";
                std::cin >> id;
                studentSystem.searchStudentById(id);
                break;
            case 0:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
