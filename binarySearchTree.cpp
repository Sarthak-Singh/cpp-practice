#include <iostream>
using namespace std;

class Node{
    Node* left;
    Node* right;
    int data;
    
    public:
        Node(int data){
            this->data = data;
        }

        // Insert method in the BST
        void insert(int value){
            if (value <= data){
                if (left == NULL){
                    left = new Node(value);
                }
                else{
                    left->insert(value);
                }
            }
            else{
                if (right == NULL){
                    right = new Node(value);
                }
                else{
                    right->insert(value);
                }
            }
        }

        // Find method in the BST
        void find(int value){
            if (value == data){
                cout << "The value " << value << " has been found." << endl;
            }
            else if (value < data && left != NULL){
                left->find(value);
            }
            else if (value > data && right != NULL){
                right->find(value);
            }
            else{
                cout << "The value " << value << " was not found." << endl;
            }
        }
        // Finding least value method in the BST
        int findMin(){
            if (left == NULL){
                return data;
            }
            else{
                return left->findMin();
            }
        }
        // Finding max value method in the BST
        int findMax(){
            if (right == NULL){
                return data;
            }
            else{
                return right->findMax();
            }
        }

        // Print InOrder method BST
        void printInOrder(){
            if (left != NULL){
                left->printInOrder();
            }
            cout << data << " ";
            if (right != NULL){
                right->printInOrder();
            }
        }
        // Print PreOrder method BST
        void printPreOrder(){
            cout << data << " ";
            if (left != NULL){
                left->printPreOrder();
            }
            if (right != NULL){
                right->printPreOrder();
            }
        }
        // Print PostOrder method BST
        void printPostOrder(){
            if (left != NULL){
                left->printPostOrder();
            }
            if (right != NULL){
                right->printPostOrder();
            }
            cout << data << " ";
        }
};

int main(){
    cout << "Enter the value of the root node: ";
    int value;
    cin >> value;
    Node* tree = new Node(value);
    cout << "Enter the number of child nodes in the tree: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        int value;
        cin >> value;
        tree->insert(value);
    }
    cout << "===================================" << endl;
    tree->printPreOrder(); cout << " => Pre Order Traversal"; cout << endl;
    tree->printInOrder(); cout << " => In Order Traversal"; cout << endl;
    tree->printPostOrder(); cout << " => Post Order Traversal"; cout << endl;

    tree->find(33);
    tree->find(13);
    tree->find(18);

    cout << "The minimum value in the tree is: " << tree->findMin() << endl;
    cout << "The maximum value in the tree is: " << tree->findMax() << endl;
    return 0;
}