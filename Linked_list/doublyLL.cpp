#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    // Constructor to initialize the node with a given value
    Node (int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    void insertAtIndex(int index, int key) {
        Node *newNode = new Node(key);
        Node *temp = head;
        if(index == 0){                     // insertion at head
            newNode -> next = head;
            if(head != NULL) head -> prev = newNode;
            head = newNode; 
        }
        else{
            // reach 1 before
            int i = 0;
            while(i < index-1){
                temp = temp -> next;
                i++;
            }
            Node *nextNode = temp -> next;      // if temp is tail, nextNode is NULL
            temp -> next = newNode;
            newNode -> prev = temp;
            newNode -> next = nextNode;         // if nextNode is after tail, this is NULL ✔️
            // checking whether we are inserting at tail, NULL -> prev = newNode ❌
            if(nextNode != NULL) nextNode -> prev = newNode;
        //this could also be done 
        /*
            newNode -> next = temp -> next;
            newNode -> prev = temp;
            if(temp -> next != NULL) temp -> next -> prev = newNode;
            temp -> next = newNode;
        */
        //codechef method
        /*
            Node *temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp -> next;
            }
            Node *A = temp;
            Node *B = temp -> next;
            // Update pointers to insert newNode between A and B
            A -> next = newNode;
            if (B != NULL) B -> prev = newNode;
            newNode -> next = B;
            newNode -> prev = A;
        */
        }
    }

    void deleteNode(int key){
        Node *temp = head;
        // find node
        while(temp != NULL && temp -> data != key){
            temp = temp -> next;
        }
        //not found
        if(temp == NULL) return;

        Node* nextNode = temp -> next;
        // if deleting head
        if(temp -> prev == NULL) head = nextNode;
        else temp -> prev -> next = nextNode;

        // checking whether tail
        if(temp -> next != NULL) temp -> next -> prev = temp -> prev;
        delete temp; 
        // delete pointer deletes the object currently pointed to by that pointer.
        // It does not delete the pointer variable itself, nor the object pointed to by some other pointer.
    /*
        // Update previous node
        if (temp->prev != NULL) temp->prev->next = temp->next;
        else head = temp->next;
        // Update next node
        if (temp->next != NULL) temp->next->prev = temp->prev;
        delete temp;
    */

    // DELETING ALL OCCURRENCES
    /*
        while (temp != NULL) {
        if (temp->data == key) {
            Node* nextNode = temp->next;

            if (temp->prev != NULL) temp->prev->next = temp->next;
            else head = temp->next;

            if (temp->next != NULL) temp->next->prev = temp->prev;

            delete temp;
            temp = nextNode;
        }
        else temp = temp->next;
        }
    */ 
    }

    void printValues() {
        if (head == NULL) {
            return;
        } else {
            Node* current = head;
            while (current != NULL) {
                cout << current -> data << ' ';
                current = current -> next;
            }
            cout << '\n';
        }
    }

};

 int main() {
    int n, index, key;
    cin >> n >> index >> key;
    
    LinkedList* list = new LinkedList();
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        list -> insertAtIndex(i, a);
    }
    list -> insertAtIndex(index, key);
    list -> printValues();
    list -> deleteNode(key);
    list -> printValues();
}