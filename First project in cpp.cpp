# include <iostream>
# include <vector>
# include <string>
using namespace std;
class person {
    protected:
    string name;
    string subject;
    int Cnic;
    int age;
    public:
    person() : name(""), subject(""), Cnic(0), age(0) {}
    void setName(string n) { name = n; }
    void setSubject(string s) { subject = s; }
    void setCnic(int c) { Cnic = c; }
    void setAge(int a) { age = a; }

    string getName () const { return name; }
    string getSubject() const { return subject; }
    int getCnic() const { return Cnic; }
    int getAge() const { return age; }

}
