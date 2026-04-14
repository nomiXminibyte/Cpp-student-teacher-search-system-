#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class - Person
class Person {
    protected:
        string name;
        int age;
        int cnic;
        string subject;
    
    public:
        Person() : name(""), age(0), cnic(0), subject("") {}
        
        virtual ~Person() {}
        
        void setName(string n) { name = n; }
        void setAge(int a) { age = a; }
        void setCnic(int c) { cnic = c; }
        void setSubject(string s) { subject = s; }
        
        string getName() const { return name; }
        int getAge() const { return age; }
        int getCnic() const { return cnic; }
        string getSubject() const { return subject; }
        
        virtual void display() const = 0;
};

// Student class inheriting from Person
class Student : public Person {
    private:
        int rollNumber;
    
    public:
        Student() : Person(), rollNumber(0) {}
        
        void setRollNumber(int r) { rollNumber = r; }
        int getRollNumber() const { return rollNumber; }
        
        void display() const override {
            cout << "\nStudent Details:" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "CNIC: " << cnic << endl;
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Subject: " << subject << endl;
        }
};

// Teacher class inheriting from Person
class Teacher : public Person {
    public:
        Teacher() : Person() {}
        
        void display() const override {
            cout << "\nTeacher Details:" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "CNIC: " << cnic << endl;
            cout << "Subject: " << subject << endl;
        }
};

// DataManager class - Manages all teacher and student records
class DataManager {
    private:
        vector<Teacher> teachers;
        vector<Student> students;
    
    public:
        DataManager() {}
        
        DataManager() {}
        
        // Add teacher to database
        void addTeacherData() {
            Teacher t;
            cout << "\n--- Add Teacher Data ---" << endl;
            cout << "Enter Teacher Name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            t.setName(name);
            
            cout << "Enter Age: ";
            int age;
            cin >> age;
            t.setAge(age);
            
            cout << "Enter CNIC: ";
            int cnic;
            cin >> cnic;
            t.setCnic(cnic);
            
            cout << "Enter Subject: ";
            cin.ignore();
            string subject;
            getline(cin, subject);
            t.setSubject(subject);
            
            teachers.push_back(t);
            cout << "Teacher added successfully!" << endl;
        }
        
        // Add student to database
        void addStudentData() {
            Student s;
            cout << "\n--- Add Student Data ---" << endl;
            cout << "Enter Student Name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            s.setName(name);
            
            cout << "Enter Age: ";
            int age;
            cin >> age;
            s.setAge(age);
            
            cout << "Enter CNIC: ";
            int cnic;
            cin >> cnic;
            s.setCnic(cnic);
            
            cout << "Enter Roll Number: ";
            int rollNumber;
            cin >> rollNumber;
            s.setRollNumber(rollNumber);
            
            cout << "Enter Subject: ";
            cin.ignore();
            string subject;
            getline(cin, subject);
            s.setSubject(subject);
            
            students.push_back(s);
            cout << "Student added successfully!" << endl;
        }
        
        // Display all teachers
        void displayAllTeachers() {
            cout << "\n--- All Teachers Data ---" << endl;
            if(teachers.empty()) {
                cout << "No teachers found!" << endl;
                return;
            }
            for(size_t i = 0; i < teachers.size(); i++) {
                cout << "\nTeacher " << (i+1) << ":";
                teachers[i].display();
            }
        }
        
        // Display all students
        void displayAllStudents() {
            cout << "\n--- All Students Data ---" << endl;
            if(students.empty()) {
                cout << "No students found!" << endl;
                return;
            }
            for(size_t i = 0; i < students.size(); i++) {
                cout << "\nStudent " << (i+1) << ":";
                students[i].display();
            }
        }
        
        // Search record by name
        void searchByName() {
            cout << "\n--- Search Record by Name ---" << endl;
            string searchName;
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, searchName);
            
            bool found = false;
            
            // Search in teachers
            for(size_t i = 0; i < teachers.size(); i++) {
                if(teachers[i].getName() == searchName) {
                    cout << "\nTeacher Found:";
                    teachers[i].display();
                    found = true;
                    return;
                }
            }
            
            // Search in students
            for(size_t i = 0; i < students.size(); i++) {
                if(students[i].getName() == searchName) {
                    cout << "\nStudent Found:";
                    students[i].display();
                    found = true;
                    return;
                }
            }
            
            if(!found) {
                cout << "No record found with name: " << searchName << endl;
            }
        }
        
        // Initialize with sample records
        void initializeRecords() {
            // Add sample student
            Student s1;
            s1.setName("Muhammad Nouman");
            s1.setAge(25);
            s1.setCnic(123456789);
            s1.setRollNumber(123456);
            s1.setSubject("Computer Science");
            students.push_back(s1);
            
            // Add sample teacher
            Teacher t1;
            t1.setName("Sir Majeed Sab");
            t1.setAge(50);
            t1.setCnic(987654321);
            t1.setSubject("Computer Science");
            teachers.push_back(t1);
            
            cout << "Sample records added successfully!" << endl;
        }
};

// Main function
int main() {
    DataManager manager;
    manager.initializeRecords();
    
    int choice;
    bool running = true;
    
    while(running) {
        
        cout << "1. Add Teacher Data" << endl;
        cout << "2. Add Student Data" << endl;
        cout << "3. Search Record by Name" << endl;
        cout << "4. Search all Teacher Records" << endl;
        cout << "5. Search all Student Records" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        if(choice == 1){
            cout << "Adding Teacher Data..." << endl;
            manager.addTeacherData();
        }
        else if(choice == 2){
            cout << "Adding Student Data..." << endl;
            manager.addStudentData();
        }
        else if(choice == 3 ){
            cout << "Searching Record by Name..." << endl;
            manager.searchByName();
        }
        else if(choice == 4){
            cout << "Searching all Teacher Records..." << endl;
            manager.displayAllTeachers();
        }
        else if(choice == 5){
            cout << "Searching all Student Records..." << endl;
            manager.displayAllStudents();
        }
        else if(choice == 6){
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        }
        else{
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
