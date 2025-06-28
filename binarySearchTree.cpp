#include <iostream>
using namespace std;

class Node{
    Node* left;
    Node* right;
    int data;
    
    public:
        Node(int data){
            this->data = data;
            left = right = NULL;
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

        // Delete node method in the BST
        Node* deleteNode(int value){
            // Traversing to the node
            if (data > value && left != NULL){
                left = left->deleteNode(value);
            }
            else if (data < value && right != NULL){
                right = right->deleteNode(value);
            }
            // Actual Deletion
            else{
                // Nodes with 0 or 1 leaf nodes
                if (left == NULL){
                    Node* temp = right;
                    free(this);
                    return temp;
                }
                else if (right == NULL){
                    Node* temp = left;
                    free(this);
                    return temp;
                }
                // Nodes with 2 left nodes
                else{
                    data = right->findMin();
                    right = right->deleteNode(data);
                }
            }
            return this;
        }
};

int main(){
    Node* tree = NULL;
    cout << "Enter the number of nodes in the tree: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        int value;
        cin >> value;
        if (i == 0){
            tree = new Node(value);
        }
        else{
            tree->insert(value);
        }
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

    tree->deleteNode(15);

    tree->printInOrder(); cout << " => New In Order Traversal"; cout << endl;
    return 0;
}