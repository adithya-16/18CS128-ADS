#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* head;

    public:
        void insert(int data) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = this->head;
            this->head = newNode;
        }

        void display() {
            cout << endl;
            if(!this->head) {
                cout << "EMPTY LIST" << endl;
                return;
            }
            Node *curr = this->head;
            while(curr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
            return;
        }

        Node* reverseDriver(Node* head, int k) {
            Node *prev = NULL, *next = NULL;
            Node *curr = head;
            int count = 0;
            while(curr && count < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if(next)
                head->next = this->reverseDriver(next, k);
            return prev;
        }

        void reverse(int k) {
            this->head = this->reverseDriver(this->head, k);
            return;
        }

        LinkedList() {
            this->head = NULL;
        }
};

int main() {
    LinkedList list;
    int choice, data, k;

    while(true) {
        cout << "\nEnter operation:"
            << "\n1. Insert at the beginning"
            << "\n2. Display the list"
            << "\n3. Reverse every k nodes"
            << "\n4. Exit" << endl;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insert(data);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter k: ";
                cin >> k;
                list.reverse(k);
                break;
            default:
                cout << "Program exit" << endl;
                return 0;
        }
    }
    return 0;
}
