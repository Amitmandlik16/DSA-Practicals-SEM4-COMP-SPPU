#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    int roll;
    string name;
    string div;
    string address;
};


void add();
void deletes(int roll);
void display(int roll);

int main() {
    char choice;
    do {
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case '1':
                add();
                break;
            case '2':
                int rollNum;
                cout << "Enter roll number of the student to delete: ";
                cin >> rollNum;
                deletes(rollNum);
                break;
            case '3':
                int displayroll;
                cout << "Enter roll number of the student to display: ";
                cin >> displayroll;
                display(displayroll);
                break;
	    case'4':
                cout << "Exit";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != '4');

    return 0;
}


void add() 
{
    ofstream outfile("student_info.txt", ios::app);
    Student newStudent;
    cout << "Enter roll number: ";
    cin >> newStudent.roll;
    cout << "Enter name: ";
    cin.ignore(); 
    getline(cin, newStudent.name);
    cout << "Enter division: ";
    getline(cin, newStudent.div);
    cout << "Enter address: ";
    getline(cin, newStudent.address);

    outfile << newStudent.roll << " " << newStudent.name << " " << newStudent.div << " " << newStudent.address << endl;
    outfile.close();
    cout << "Student added successfully.\n";
}


void deletes(int roll) 
{
    ifstream infile("student_info.txt");
    ofstream tempFile("temp.txt");

    Student student;
    bool found = false;
    while (infile >> student.roll >> student.name >> student.div >> student.address) {
        if (student.roll != roll) {
            tempFile << student.roll << " " << student.name << " " << student.div << " " << student.address << endl;
        } else {
            found = true;
        }
    }
    infile.close();
    tempFile.close();

    if (!found)
    {
        cout << "Student with roll number " << roll << " not found.\n";
    } 
    else 
    {
        remove("student_info.txt");
        rename("temp.txt", "student_info.txt");
        cout << "Student with roll number " << roll << " deleted successfully.\n";
    }
}


void display(int roll) 
{
    ifstream infile("student_info.txt");
    Student student;
    bool found = false;
    while (infile >> student.roll >> student.name >> student.div >> student.address) {
        if (student.roll == roll) 
	{
            found = true;
            cout << "Roll Number: " << student.roll << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.div << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }
    infile.close();
    if (!found) {
        cout << "Student with roll number " << roll << " not found.\n";
    }
}