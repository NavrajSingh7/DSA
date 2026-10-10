#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*& head, int data) {

    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void display(Node* head) {

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

void splitCircularList(Node* head, Node*& head1, Node*& head2) {

    if (head == NULL) {
        head1 = NULL;
        head2 = NULL;
        return;
    }
    if (head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }
    
    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    head1 = head;
    head2 = slow->next;
    if (fast->next->next == head) {
        fast = fast->next;
    }
    slow->next = head1;
    fast->next = head2;
}


int main() {

    Node* head = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }
    cout << "\nOriginal Circular Linked List: ";
    display(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    splitCircularList(head, head1, head2);
    cout << "\nFirst Circular List: ";
    display(head1);
    cout << "Second Circular List: ";
    display(head2);

    return 0;
}