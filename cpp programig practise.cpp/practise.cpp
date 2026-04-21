#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// Base class - Person
class Person {
protected:
    string name;
    int age;
    string cnic;

public:
    Person(string n, int a, string c) : name(n), age(a), cnic(c) {}
    virtual ~Person() = default;

    string get_name() const { return name; }

    virtual void display() const = 0;
};

// Student class
class Student : public Person {
private:
    int rollNumber;
    string subject;

public:
    Student(string n, int a, string c, int r, string s)
        : Person(n, a, c), rollNumber(r), subject(s) {}

    void display() const override {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subject: " << subject << endl;
    }
};

// Teacher class
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string n, int a, string c, string s)
        : Person(n, a, c), subject(s) {}

    void display() const override {
        cout << "\nTeacher Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Subject: " << subject << endl;
    }
};

// DataManager class
class DataManager {
private:
    vector<unique_ptr<Person>> records;

public:
    void addTeacherData() {
        cout << "\n--- Add Teacher Data ---" << endl;

        cin.ignore();
        string name, cnic, subject;
        int age;

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter CNIC: ";
        cin >> cnic;

        cin.ignore();
        cout << "Enter Subject: ";
        getline(cin, subject);

        records.push_back(make_unique<Teacher>(name, age, cnic, subject));
    }

    void addStudentData() {
        cout << "\n--- Add Student Data ---" << endl;

        cin.ignore();
        string name, cnic, subject;
        int age, roll;

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter CNIC: ";
        cin >> cnic;

        cout << "Enter Roll Number: ";
        cin >> roll;

        cin.ignore();
        cout << "Enter Subject: ";
        getline(cin, subject);

        records.push_back(make_unique<Student>(name, age, cnic, roll, subject));
    }

    void displayAll() {
        if (records.empty()) {
            cout << "No records found!" << endl;
            return;
        }

        for (const auto& p : records) {
            p->display();
        }
    }

    void searchByName() {
        cout << "\nEnter name to search: ";
        cin.ignore();
        string searchName;
        getline(cin, searchName);

        for (const auto& p : records) {
            if (p->get_name() == searchName) {
                p->display();
                return;
            }
        }

        cout << "No record found!" << endl;
    }
};

int main() {
    DataManager manager;

    int choice;
    while (true) {
        cout << "\n1. Add Teacher\n2. Add Student\n3. Search\n4. Display All\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
            manager.addTeacherData();
        else if (choice == 2)
            manager.addStudentData();
        else if (choice == 3)
            manager.searchByName();
        else if (choice == 4)
            manager.displayAll();
        else if (choice == 5)
            break;
        else
            cout << "Invalid choice\n";
    }

    return 0;
}