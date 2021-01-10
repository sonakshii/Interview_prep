//here we are making a hash maps where key is the type of an object and value is int type
//define your own hash function
//do overloading of == for the case of same name but differnt rollno!!!
#include <iostream>
#include <unordered_map> 
#include <string>
using namespace std;

class Student
{
    public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f,string l,string no)
    {
        firstname=f;
        lastname=l;
        rollno=no;
    }

    bool operator==(const Student &s) const
    {
        return (rollno==s.rollno?true:false);
    }
 
};

class HashFn{
    public:
    //size_t is unsigned int type of datatype
    size_t operator()(const Student &s) const   //this is method to do operator overloading
    {
        return s.firstname.length()+s.lastname.length();
    }
};


int main() 
{
    unordered_map<Student,int,HashFn> student_map;
    Student s1("Sonakshi","Gupta","001");
    Student s2("Aditi","Gupta","002");
    Student s3("Gupta","Gupta","003");
    Student s4("Sonakshi","Gupta","004");

    student_map[s1]=100;
    student_map[s2]=120;
    student_map[s3]=11;
    student_map[s4]=45;

    for(auto s:student_map)
    {
        cout<<s.first.firstname<<" "<<s.first.rollno<<endl<<"MARKS: "<<s.second<<endl;
    }
    return 0;
}