
#include <iostream>
#define SIZE 20

using namespace std;

class LinearProbing {
        
        string name[SIZE], tel[SIZE];
        char status[SIZE];          //O,D,E
        int n;
    public:
        LinearProbing() {
            cout << endl << "Enter table size: ";
            cin >> n;
            
            for(int i = 0; i < n; i++) {
                name[i] = "";
                tel[i] = "";
                status[i] = 'E';
            }
        }
        void display();
        void insert(string nm, string telno);   
        int hashf(string key);
        void probeSeq(string, string);          
        void search(string);
        void probeSearch(string);
};

void LinearProbing::display() {
    cout << endl << "Index\tClint's Name\tTelephone no\tStatus";
    for(int i = 0; i < n; i++) {
        cout << endl << i << "\t\t" << name[i] << "\t\t" << tel[i] << "\t" << status[i];
    }
}

int LinearProbing::hashf(string key) {
    
  
    int asciiSum = 0;
    
    for(int i = 0; i < key.length(); i++) {
        asciiSum += key[i];
    }
    return asciiSum % n;
}
void LinearProbing::insert(string nm, string telno) {
    int index = hashf(nm);
    cout << endl << "Index: "<<index;
    if(status[index] == 'E') {
        name[index] = nm;
        tel[index] = telno;
        status[index] = 'O';
    }
    else
        probeSeq(nm, telno);                    //call
}

void LinearProbing::probeSeq(string nm, string telno) {
    int h0 = hashf(nm);
    int seq;
    for(int i = 1; i < n; i++) {
        // hi(x) = (h0 + f(i)) % tablesize f(i) = i
        seq = (h0 + i) % n;
        if(status[seq] == 'E') {
            name[seq] = nm;
            tel[seq] = telno;
            status[seq] = 'O';
            return;
        }
    }
}

void LinearProbing::search(string nm) {
    int index = hashf(nm);
    cout << endl << "Index: " << index;
    if(name[index] == nm && status[index] == 'O') {
        cout << endl << "Record found at location :" << index;
        cout << endl << name[index] << " -> " << tel[index];
    }
    else
        probeSearch(nm);
}

void LinearProbing::probeSearch(string nm) {
    int h0 = hashf(nm);
    int seq;
    for(int i = 1; i < n; i++) {
        
        seq = (h0 + i) % n;
        if(name[seq] == nm && status[seq] == 'O') {
            cout<< endl << "Record found at location: " << seq;
            cout<< endl << name[seq] <<" -> "<< tel[seq];
            return;
        }
        if(status[seq] == 'E') {
            cout << endl << "Record not found";
            return;
        }
    }
}

int main() {
    LinearProbing obj;
    string name,tel;
    int ch;
    
    do {
        cout << endl
             << "--------Menu--------" << endl
             << "1. Insert" << endl 
             << "2. Display" << endl
             << "3. Search" << endl
             << "4. Exit";
        cout << endl << "Enter Your Choice:";
        cin >> ch;
        cout << "--------------------" << endl;
        
        switch(ch) {
            case 1:
                cout << endl << "Enter Client's Name: ";
                cin >> name;
                cout << endl << "Enter Telephone number: ";
                cin >> tel;
                obj.insert(name,tel);
                break;
            case 2:
                obj.display();
                break;
            case 3:
                cout << endl << "Enter Client's Name to be searched: ";
                cin >> name;
                obj.search(name);
                break;
            case 4:
                exit(0);
            default:
                cout << endl << "Invalid choice";
        }
    } while(ch != 4);
    
    return 0;
}
