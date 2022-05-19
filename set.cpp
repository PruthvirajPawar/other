

#include<iostream>
using namespace std;

class SetOp {
        int a[10];
        int n;
    public:
        SetOp() {
            n = 5;
            for(int i = 0; i < 10; i++) {
                a[i] = 0;
            }
        }
        void add();
        void display();
        int contains(int);
        void size();
        void union_set(SetOp);
        void intersection_set(SetOp);
        void difference_set(SetOp);
        void subset(SetOp);
        void remove(int);
};

void SetOp::add() {               
    int value, i;
    cout << endl << "Enter no of elements: ";
    cin >> n;
    
    for(i = 0; i < n; ) {
        cout << endl << "Enter elements: ";
        cin >> value;
        if(contains(value) == -1) { 
            a[i]=value;
            i++;
        }
        else
            cout << endl << "Elements is already exist";
    }
}

void SetOp::display() {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int SetOp::contains(int val) {
    for(int i = 0; i < n; i++) {
        if(a[i] == val)
            return i;
    }
    return -1;
}

void SetOp::remove(int val) {       
    if(this -> contains(val) == -1) 
        cout << endl << val << "does not exist";
    
    else {                          
        int index = contains(val);
        while(index < n) {
            a[index] = a[index + 1];
            index++;
        }
        n--;
    }
}

void SetOp::union_set(SetOp S2){    
    cout << endl << "Enter second set:";
    S2.add();
    SetOp result;
    int i, j;
    
    for(i = 0; i < n; i++)
        result.a[i] = this -> a[i];
    
    for(j = 0; j < S2.n; j++) {
        if(this -> contains(S2.a[j]) == -1) {  
            result.a[i] = S2.a[j];
            i++;
        }
    }
    
    cout << endl << "Union set operations: ";
    result.n = i;
    result.display();
}

void SetOp::intersection_set(SetOp S2) {
    cout << endl << "Enter second set: ";
    S2.add();
    SetOp result;                   
    int j = 0;
    
    for(int i = 0; i < S2.n; i++) {
        if(this -> contains(S2.a[i]) != -1) {
            result.a[j] = S2.a[i];
            j++;
        }
    }
    
    cout << endl << "Intersection of elements: ";
    result.n = j;
    result.display();
}

void SetOp::difference_set(SetOp S2) {
    cout << endl << "Difference set operation";
    cout << endl << "Enter 2nd set:";
    S2.add();
    SetOp result;                  
    int j = 0;
    
    for(int i = 0; i < this -> n; i++) {
        if(S2.contains(this -> a[i]) == -1) {
            result.a[j] = this -> a[i];
            j++;
        }
    }
    cout << endl << "Difference between sets is: ";
    result.n = j;
    result.display();
}

void SetOp::subset(SetOp S2) {
    int flag = 0;
    cout << "Subset operation";    
    cout << "Enter second set:";
    S2.add();
    for(int i = 0; i < S2.n; i++) {
        if(this -> contains(S2.a[i]) == -1) {   
            cout << "Set2 is not a subset of set1";
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << endl << "Set2 is a setof set1";
    }
}

int main() {
    int val;
    SetOp obj1;
    SetOp obj2;
    int ch;
    do {
        cout << endl << "---------------" << endl;
        cout << "Set operation" << endl;
        cout << "1.accept" << endl
             << "2.display" << endl
             << "3.remove" << endl 
             << "4.union of 2set" << endl 
             << "5.intersection_set" << endl
             << "6.difference_set" << endl 
             << "7.subset" << endl 
             << "8.exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> ch;
        cout << "--------------" << endl;

        switch(ch) {
            case 1:
                obj1.add();
                break;
            case 2:
                obj1.display();
                break;
            case 3:
                int val;
                cout << "Enter value to be deleted: ";
                cin >> val;
                obj1.remove(val);
                break;
            case 4:
                obj1.union_set(obj2);
                break;
            case 5:
                obj1.intersection_set(obj2);
                break;
            case 6:
                obj1.difference_set(obj2);
                break;
            case 7:
                obj1.subset(obj2);
                break;
            case 8:
                exit(0);
                break;
            default:
                cout << "Invalid" << endl;
        }
    } while(ch != 8);
    return 0;
}
