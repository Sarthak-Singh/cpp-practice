#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        //Default Constructor
        Node() {
            data = 0;
            next = NULL;
        }
        //Parameterised Constructor
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
};

class linkedlist{
public:
    Node* head;
    //Default Constructor
    linkedlist(){
        head = NULL;
    }

    // Add link (push)
    void insertAtHead(int data){
        Node* newNode = new Node(data, head);
        this->head = newNode;
    }
    // Insert link at end of LL
    void insertAtEnd(int data){
        Node* ptr = this->head;
        if (head == NULL || head->next == NULL) {
            cout << "List is empty or has only one node. No reversal needed." << endl;
            return;
        }
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        Node* newNode = new Node(data, NULL);
        ptr->next = newNode;
    }
    // Insert after a given node
    void insertAfterGivenNode(int data, int key){
        Node* ptr = this->head;
        while (ptr->data != key){
            ptr = ptr->next;
        }
        Node* newNode = new Node(data,ptr->next);
        ptr->next = newNode;
    }

    // Remove Link (pop)
    void removeAtHead(){
        Node* ptr = this->head;
        this->head = head->next;
        free(ptr);
    }
    // Remove from the end of LL
    void removeAtEnd(){
        Node* ptr;
        Node* ptr2 = this->head;
        while (ptr2->next != NULL){
            ptr = ptr2;
            ptr2 = ptr2->next;
        }
        ptr->next = NULL;
        free(ptr2);
    }
    // Remove a certain node in LL
    void removeGivenNode(int key){
        Node* ptr;
        Node* ptr2 = this->head;
        while (ptr2->data != key){
            ptr = ptr2;
            ptr2 = ptr2->next;
        }
        ptr->next = ptr2->next;
        free(ptr2);
    }

    // Print Linked List
    void printList(){
        Node* current = this->head;
        while (current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Finding loops/cycles in the linked list
    void findLoopInLinkedList(){
        Node* slow = head; Node* fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                cout << "There is a loop/cycle present in the linked list." << endl;
                return;
            }
        }
        cout << "There is no loop/cycle present in the linked list." << endl;
    }
    
    //Reversing the linked list
    void reverseLinkedList(){
        Node* prev = nullptr; 
        Node* current = head; 
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next; // Store next node
            current->next = prev; // Reverse current node's pointer
            prev = current;       // Move prev and current one step forward
            current = next;
        }
        head = prev;
    }
};


int main(){
    linkedlist list;

    // Insert elements into the linked list at the beginning
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);
    list.insertAtHead(50);
    list.insertAtHead(60);
    // Example output to verify the linked list
    list.printList();
    //Remove the first element
    list.removeAtHead();
    //Example output to verify the linked list
    list.printList();
    //Insert element into the linked list at the end
    list.insertAtEnd(90);
    //Example output to verify the linked list
    list.printList();
    //Insert element into linked list after a given key
    list.insertAfterGivenNode(55,30);
    //Example output to verify the linked list
    list.printList();
    // Removing from end of LL
    list.removeAtEnd();
    list.removeAtEnd();
    // Example output to verify the linked list
    list.printList();
    // Adding more elements
    list.insertAtHead(77);
    list.insertAtEnd(99);
    //Example output to verify the linked list
    list.printList();
    // Removing a given key
    list.removeGivenNode(55);
    //Example output to verify the linked list
    list.printList();
    //Reverse the linked list
    list.reverseLinkedList();
    //Example output to verify the linked list
    list.printList();
    //Checking loops in the linked list
    list.findLoopInLinkedList();

    return 0;
}