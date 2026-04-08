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

class teacher : public person {
    
};

vector<person> records;

void search_record(const string& search_name) {
    bool found = false;
    for (int i = 0; i < records.size(); ++i) {
        if (records[i].name == search_name) {
            cout << "Record " << i << ":\n";
            cout << "  Name: " << records[i].name << endl;
            cout << "  Age: " << records[i].age << endl;
            cout << "  CNIC: " << records[i].cnic << endl;
            cout << "  Subject: " << records[i].subject << endl;
            cout << "  Roll Number: " << records[i].rollnumber << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No record found with name: " << search_name << endl;
    }
}

int main() {
    person p1;
    p1.name = "Muhammad Nouman";
    p1.age = 25;
    p1.cnic = 123456789;    
    student s1;
    s1.name = "Muhammad Nouman";
    s1.age = 25;
    s1.cnic = 123456789;
    s1.rollnumber = 123456;
    s1.subject = "Computer Science";
    cout << "Student Name: " << s1.name << endl;
    cout << "Student Age: " << s1.age << endl;
    cout << "Student CNIC: " << s1.cnic << endl;
    cout << "Student Roll Number: " << s1.rollnumber << endl;
    cout << "Student Subject: " << s1.subject << endl;

    teacher t1;
    t1.name = "Sir Majeed Sab";
    t1.age = 50;
    t1.cnic = 987654321;
    
    t1.subject = "Computer Science";

    records.push_back(s1);
    records.push_back(t1);

    cout << "Teacher Name: " <<t1.name << endl;
    cout << "Teacher Age: " << t1.age << endl;
    cout << "Teacher CNIC: " << t1.cnic << endl;
    cout << "Teacher Subject: " << t1.subject << endl;

    string searchName;
    cout << "Enter the name to search: ";
    getline(cin, searchName);
    search_record(searchName);

    if (s1.age > t1.age) {
        cout << "Student is older than teacher." << endl;
    } else if (s1.age < t1.age) {
        cout << "Teacher is older than student." << endl;
    } else {
        cout << "Student and teacher are of the same age." << endl;
    }
    return 0;
} 