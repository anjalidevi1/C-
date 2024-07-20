#include <iostream>
#include <string>
using namespace std;
// Base class Course
class Course {
    protected: int ch;
public:
void msg(){
    cout<<"\n Welcome to XYZ College";
}
    public:
    int AdmDetails()  {
        cout<<"\n Welcome To Admission Section"<<endl;
        cout<<"Select Course type" <<endl;
        cout<<"Enter your choice 1 for UG 2 for PG 3 for Diploma Course 4 to exit"<<endl;
        cin>>ch;
        if(ch==1){
            return 1;
        }
        else if (ch==2){
            return 2;
        }
        else if(ch==3){
            return 3;
        }
        else{
            return 4;
        }
    }
           };
// UGCourse class inheriting from Course
class UGCourse : public Course {
public:
void msg(){
    cout<<"\n Welcome to UGCourse Section ";
}
public:
        void UGDetails(string CName,string CCode,string UName)  {
        cout << "UG Course Details:" << endl;
        cout << "Course Name:" <<CName<< endl;
        cout << "Course Code:" <<CCode<< endl;
        cout << "University Name: " << UName << endl;    }};
// PGCourse class inheriting from Course
class PGCourse : public Course {
    public:
void msg(){
    cout<<"\n Welcome to PG Course section";
}
public:
    void PGdisplayDetails(string CName,string CCode,string UName)  {
         cout << "PG Course Details:" << endl;
        cout << "Course Name:" <<CName<< endl;
        cout << "Course Code:" <<CCode<< endl;
        cout << "University Name: " << UName << endl; } };
// DiplomaCourse class inheriting from Course
class DiplomaCourse : public Course {
    public:
void msg(){
    cout<<"\n Welcome to Diploma Course Section";
}
public:
    void DPdisplayDetails(string CName,string CCode,string IName)  {
        cout << "Diploma Course Details:" << endl;
        cout << "Course Name:" <<CName<< endl;
        cout << "Course Code:" <<CCode<< endl;
        cout << "Institution Name: " << IName << endl;   }  };
int main() {
    int ch1;
    UGCourse ugobj;
    PGCourse pgobj;
    DiplomaCourse dipobj;
    ch1=dipobj.AdmDetails();

    if(ch1==1){
        ugobj.msg();
ugobj.UGDetails("Bachelor of Science", "UG101", "XYX University");

    cout << endl;
    }
    else if(ch1==2){
        pgobj.msg();
    pgobj.PGdisplayDetails("Master of Science", "PG101", "XYZ University");
    cout << endl;
    }
    else if(ch1==3){
        dipobj.msg();
    dipobj.DPdisplayDetails("Diploma in Web Development", "DIP101", "WebTech Institute");
    }
    else if(ch1==4){
       cout<<"\n Thanks";
    }

    return 0;}
