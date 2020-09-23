#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* link;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* XOR(Node* x, Node* y) {
            return (Node*) ((uintptr_t)(x) ^ (uintptr_t)(y));
        }
    public:
        void insertBeginning(int data) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->link = this->head;
            if(this->head)
                this->head->link = this->XOR(newNode,this->head->link);
            this->head = newNode;
        }
        void insertEnd(int data) {
            Node* newNode = new Node();
            newNode->data = data;
            if (!this->head) {
                newNode -> link = this->head;
                this->head = newNode;
            } 
            else {
                Node *curr = this->head;  
                Node *prev = NULL;  
                Node *next;  
                while (XOR(prev, curr->link)) {  
                    next = XOR(prev, curr->link);  
                    prev = curr;  
                    curr = next;  
                }
                newNode->link = curr;
                curr->link = XOR(prev, newNode);
            }
        }
        void deleteEnd() {
            if (!this->head) 
                return NULL;
            Node* prev = NULL, *curr = this->head, *next = XOR(prev, curr->link);
            while (next) {
                prev = curr;
                curr = next;
                next = XOR(prev, curr->link);
            }
            if (prev)
                prev->link = XOR(prev->link, curr);
            delete curr;
        }
        void deleteBeg() {
            if (!this->head) 
                return NULL;
            Node* next = this->XOR(this->head->link, NULL);
            if (next)
                next->link = this->XOR(head, next->link);
            this->head = next;
        }
        void display() {
            cout << endl;
            if(!this->head) {
                cout << "EMPTY LIST" << endl;
                return;
            }
            Node *curr = this->head;
            Node *prev = NULL;
            Node *next;
            while(curr) {
                cout << curr->data << " ";
                next = XOR(prev, curr->link);
                prev = curr;
                curr = next;
            }
        }
        DoublyLinkedList() {
            this->head = NULL;
        }
};

int main() {
    DoublyLinkedList dll;
    int choice, data;
    while(true) {
        cout << "\nEnter operation:"
            << "\n1. Insert at the beginning"
            << "\n2. Insert at the end"
            << "\n3. Display the list"
            << "\n4. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                dll.insertBeginning(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                dll.insertEnd(data);
                break;
            case 3:
                dll.display();
                break;
            default:
                cout << "Program exit" << endl;
                return 0;
        }
    }
    return 0;
}
