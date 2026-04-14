#include <iostream>
#include <vector>  
using namespace std;    
cout << "Hello, World!" << endl;
return 0;



























































































































































































































#include <iostream>
#include <vector>
#include <string>
using namespace std;
class person {
    public:
    string name;
    int age;
    int cnic;
    int rollnumber;
    string subject;

};
class student : public person {
    
};
class teacher : public person{

};

// Struct to manage teacher and student data
struct DataManager {
    vector<teacher> teachers;
    vector<student> students;
    
    // Function to add teacher data
    void addTeacherData() {
        teacher t;
        cout << "\n--- Add Teacher Data ---" << endl;
        cout << "Enter Teacher Name: ";
        cin.ignore();
        getline(cin, t.name);
        cout << "Enter Age: ";
        cin >> t.age;
        cout << "Enter CNIC: ";
        cin >> t.cnic;
        cout << "Enter Subject: ";
        cin.ignore();
        getline(cin, t.subject);
        
        teachers.push_back(t);
        cout << "Teacher added successfully!" << endl;
    }
    
    // Function to add student data
    void addStudentData() {
        student s;
        cout << "\n--- Add Student Data ---" << endl;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Enter Age: ";
        cin >> s.age;
        cout << "Enter CNIC: ";
        cin >> s.cnic;
        cout << "Enter Roll Number: ";
        cin >> s.rollnumber;
        cout << "Enter Subject: ";
        cin.ignore();
        getline(cin, s.subject);
        
        students.push_back(s);
        cout << "Student added successfully!" << endl;
    }
    
    // Function to get and display all teacher data
    void getTeacherData() {
        cout << "\n--- All Teachers Data ---" << endl;
        if(teachers.empty()) {
            cout << "No teachers found!" << endl;
            return;
        }
        for(int i = 0; i < teachers.size(); i++) {
            cout << "\nTeacher " << (i+1) << ":" << endl;
            cout << "Name: " << teachers[i].name << endl;
            cout << "Age: " << teachers[i].age << endl;
            cout << "CNIC: " << teachers[i].cnic << endl;
            cout << "Subject: " << teachers[i].subject << endl;
        }
    }
    
    // Function to get and display all student data
    void getStudentData() {
        cout << "\n--- All Students Data ---" << endl;
        if(students.empty()) {
            cout << "No students found!" << endl;
            return;
        }
        for(int i = 0; i < students.size(); i++) {
            cout << "\nStudent " << (i+1) << ":" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "CNIC: " << students[i].cnic << endl;
            cout << "Roll Number: " << students[i].rollnumber << endl;
            cout << "Subject: " << students[i].subject << endl;
        }
    }
};

int main()
{
    DataManager manager;
    
    cout << "1. Add Teacher Data" << endl;
    cout << "2. Add Student Data" << endl;
    cout << "3. Search Record by Name" << endl;
    cout <<"4. Search all Teacher Records" << endl;
    cout << "5. Search all Student Records" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;

    cin >> choice;

    if(choice == 1){
        manager.addTeacherData();
    }
    else if(choice == 2){
        manager.addStudentData();
    }
    else if(choice == 3 ){
        cout<<"Searching Record by Name..." << endl;
    }
    else if(choice == 4){
        manager.getTeacherData();
    }
    else if(choice == 5){
        manager.getStudentData();
    }
    else if(choice == 6){
        cout << "Exiting the program. Goodbye!" << endl;
        return 0;
    }
    else{
        cout << "Invalid choice. Please try again." << endl;
    }

    return 0;
}
