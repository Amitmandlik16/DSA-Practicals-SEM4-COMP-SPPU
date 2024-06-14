#include <iostream>
#include <fstream>
using namespace std;

class student
{
    public:
    int roll;
    char div;
    char name[10];
    void read()
    {
        cout<<"Enter the rolll no of the student =";
        cin>>roll;
        cout<<"Enter the name of the student =";
        cin>>name;
        cout<<"Enter the division of the student =";
        cin>>div;
    }
    void display()
    {
        cout<<"Roll no. ="<<roll<<"\n Name ="<<name<<"\n division ="<<div<<endl;
    }
};
int main()
{
    student s[20];
    student s1;
    int n,sroll,delroll;
    cout<<"Enter the number of students to write data in to the file";
    cin>>n;
        fstream fr;
        fr.open("student.txt",ios::out);
       for(int i=0;i<n;i++)
    {
        s[i].read();
        fr.write((char*)&s[i],sizeof(s[i]));
     }
        fr.close();
    cout<<"\n displaying the data";
    fstream fr1;
    fr1.open("student.txt",ios::in);
        while(!fr1.eof())
        {
            fr1.read((char*)&s1,sizeof(s1));
            s1.display();
        }
        fr1.close();
    cout<<"Enter the roll no do you want to search in file";
    cin>>sroll;
    fstream fr2;
    fr2.open("student.txt",ios::in);
        while(!fr2.eof())
        {
            fr2.read((char*)&s1,sizeof(s1));
            if(s1.roll==sroll)
            {
                cout<<"found \n ";
                s1.display();
                break;
            }
        }
        fr2.close();

    cout<<"Enter the roll number you want to delete from the database =";
    cin>>delroll;
    fstream fr3;
    fr3.open("student.txt",ios::in);
    fstream fr4;
    fr4.open("newstudent.txt",ios::out);
    while(!fr3.eof())
    {
        fr3.read((char*)&s1,sizeof(s1));
        if(s1.roll==delroll)
        {
            cout<<"found deleted \n ";
            s1.display();
            break;
        }
        else
        {
            fr4.write((char*)&s1,sizeof(s1));
        }
    }
    fr3.close();
    fr4.close();
    remove("student.txt");
    rename("newstudent.txt","student.txt");
    cout<<"\n displaying the data";

    fr1.open("student.txt",ios::in);
        while(!fr1.eof())
        {
            fr1.read((char*)&s1,sizeof(s1));
            s1.display();
        }
        fr1.close();

    return 0;
}