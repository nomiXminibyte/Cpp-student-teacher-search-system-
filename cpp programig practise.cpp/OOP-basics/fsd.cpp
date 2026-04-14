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
struct DataManager {
    vector<teacher> teachers;
    vector<student> students;
    
    void addTeacherData() {
        teacher t;
        cout << "--- Add Teacher Data ---" << endl;
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
        cout<<"Adding Teacher Data..." << endl;
        manager.addTeacherData();
    }
    else if(choice == 2){
        cout<<"Adding Student Data..." << endl;
        manager.addStudentData();
    }
    else if(choice == 3 ){
        cout<<"Searching Record by Name..." << endl;
    }
    else if(choice == 4){
        cout<<"Searching all Teacher Records..." << endl;
    }
    else if(choice == 5){
        cout<<"Searching all Student Records..." << endl;
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