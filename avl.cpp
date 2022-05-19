

#include <iostream>
using namespace std;

class Node {
        int data, height;
        Node *left, *right;
    public:
        Node() {
            data = height = 0;
            left = right = NULL;
        }

        friend class AVL;
};

class AVL {
        Node *root;
    public:
        AVL() {
            root = NULL;
        }

        Node *insert(Node *, int);
        Node *LL(Node *);
        Node *RR(Node *);
        Node *LR(Node *);
        Node *RL(Node *);
        Node *LeftRotate(Node *);
        Node *RightRotate(Node *);
        int BalanceFactor(Node *);
        int GetHight(Node *);
        void Inorder(Node *);
        void insert();
        void Inorder();
};

Node* AVL::LL(Node *root) {
    cout << "Single LL Rotation" << endl;
    root = RightRotate(root);
    return root;
}
Node* AVL::RR(Node *root) {
    cout << "Single RR Rotation" << endl;
    root = LeftRotate(root);
    return root;
}
Node* AVL::LR(Node *root) {
    cout << "Bouble LR Rotation" << endl;
    root -> left = LeftRotate(root -> left);
    root = RightRotate(root);
    return root;
}
Node* AVL::RL(Node *root) {
    cout << "Bouble RL Rotation" << endl;
    root -> right = RightRotate(root -> right);
    root = LeftRotate(root);
    return root;
}

void AVL::Inorder(Node *root) {
    // LVR
    if(root != nullptr) {
        Inorder(root -> left);
        cout << "\t" << root -> data;
        Inorder(root -> right);
    }
}

Node* AVL::RightRotate(Node *x) {  
    Node* y;                       
    y = x -> left;
    x -> left = y -> right;
    y -> right = x;
    x -> height = GetHight(x);
    y -> height = GetHight(y);
    
    return y;
}

Node* AVL::LeftRotate(Node* x) {   
    Node* y;                       
    y = x -> right;
    x -> right = y -> left;
    y -> left = x;
    x -> height = GetHight(x);
    y -> height = GetHight(y);
    
    return y;
}

Node *AVL::insert(Node *root, int val) {
    /* 1. root is empty */
    if(root == nullptr) {
        root = new Node();
        root -> data = val;
    }

    /* 2. Left */
    if(val < root -> data) {
        root -> left = insert(root -> left, val);
        if(BalanceFactor(root) == 2) {
            if(val < root -> left -> data) {
                root = LL(root);
            }
            else {
                root = LR(root);
            }
        }
    }
    
    /* 3. Right */
    if(val > root -> data) {
        root -> right = insert(root -> right, val);
        if(BalanceFactor(root) == -2) {
            if(val > root -> right -> data) {
                root = RR(root);
            }
            else {
                root = RL(root);
            }
        }
    }
    root -> height = GetHight(root);
    return root;
}

int AVL::BalanceFactor(Node* root) {
    int hl, hr;
    if(root == nullptr) {
        return 0;
    }
    if(root -> left == nullptr) {
        hl = 0;
    }
    else {
        hl = 1 + root -> left -> height;
    }

    if(root -> right == nullptr) {
        hr = 0;
    }
    else {
        hr = 1 + root -> right -> height;
    }
    return hl - hr;
}

int AVL::GetHight(Node* root) {
    int hl, hr;
    if(root == nullptr) {
        return 0;
    }
    if(root -> left == nullptr) {
        hl = 0;
    }
    else {
        hl = 1 + root -> left -> height;
    }

    if(root -> right == nullptr) {
        hr = 0;
    }
    else {
        hr = 1 + root -> right -> height;
    }

    if(hl > hr) {
        return hl;
    }
    else {
        return hr;
    }
}

void AVL::insert() {
    int val;
    cout << "Enter value which you want to insert :";
    cin >> val;
    root = insert(root, val);
}

void AVL::Inorder() {
    Inorder(root);
}

int main() {
    int choice;
    AVL object;

    do {
        cout << "----------Menu----------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Traversal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "------------------------" << endl;

        switch(choice) {
            case 1:
                object.insert();
                break;
            case 2:
                object.Inorder();
                cout << endl;
                break;
            case 3:
                cout << "Thank you exit of program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        } 
    }while(choice != 3);

    return 0;
}
