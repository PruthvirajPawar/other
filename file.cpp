

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
        int roll_number;
        char name[10];
        char division;
        char address[10];
    public:
        Student() {
            roll_number =  0;
            division = ' ';
            strcpy(name, "");
            strcpy(address,"");
        }
        void input();
        void display();         

        int getroll() {
            return roll_number;
        }
};

class Sequential_File {
        fstream file;
        Student stud;          
    public:
        void create();         
        void add();
        void search();
        void del();
        void print();           
};

void Sequential_File::create() {    
    char ch = 'y';
    file.open("binary.txt", ios::out | ios::binary);
    
    while(ch == 'y' || ch == 'Y') {
        stud.input();
        file.write((char*)&stud, sizeof(stud));
        cout << "Want to Continue....";
        cin >> ch;
    }

    file.close();
}

void Sequential_File::add() {    
    char ch = 'y';
    file.open("binary.txt", ios::app | ios::out | ios::binary);
    
    while(ch == 'y' || ch == 'Y') {
        stud.input();
        file.write((char*)&stud, sizeof(stud));
        cout << "Want to Continue....";
        cin >> ch;
    }

    file.close();
}

void Student::input() {
    cout << endl << "Enter roll number: ";
    cin  >> roll_number;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter division: ";
    cin >> division;
    cout << "Enter address: ";
    cin >> address;
}

void Sequential_File::print() {
    file.open("binary.txt", ios::in | ios::binary);
    if(!file) {
        cout << "File not found" << endl;
        exit(0);
    }
    else {
        file.read((char*)&stud, sizeof(stud));
        while(!file.eof()) {
            stud.display();
            file.read((char*)&stud, sizeof(stud));
        }
    }
    file.close();
}

void Student::display() {
    cout << endl << roll_number 
         << "\t" << division 
         << "\t" << name 
         << "\t" << address 
         << endl;
}

void Sequential_File::search() {   
    int n, flag = 0;
    cout << "Enter roll no. of student that should be searched: ";
    cin >> n;
    file.open("binary.txt", ios::in | ios::binary);
    if(!file) {
        cout << "File not found";
        exit(0);
    }
    else{
        file.read((char*)&stud, sizeof(stud));
        while(!file.eof()) {
            if(n == stud.getroll()) {
                stud.display();
                cout << "Record found" << endl;
                break;
            }
            else {
                file.read((char*)&stud, sizeof(stud));
                flag = 1;
            }
        }
        if(flag == 1)
            cout << "Record not found" << endl; 
    }
    file.close();    
}

int main() {
    Student obj;
    Sequential_File obj2;
    int ch;
    do {
      cout << "----------------------------" << endl;
      cout << "1. Create data file" << endl;
      cout << "2. Add data into file" << endl;
      cout << "3. Search data into file" << endl;
      cout << "4. Print data from file" << endl;
      cout << "5. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> ch;
      cout << "----------------------------" << endl;
      switch(ch) {
        case 1:
          obj2.create();
          break;
        case 2:
          obj2.add();
          break;
        case 3:
          obj2.search();
          break;
        case 4:
          obj2.print();
          break;
        case 5:
          cout << "Bye Bye!!!" << endl;
        default:
          cout << "No such choice" << endl;
      }

    } while(ch != 5);

    return 0;
}
