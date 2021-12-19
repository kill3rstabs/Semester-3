#include <climits>
#include <iostream>
#include <vector>
using namespace std;

string encodedString;

class Node {
public:
    char data;
    int priority;
    Node *left;
    Node *right;
    Node *next;

    Node(char data, int priority) {
        this->data = data;
        this->priority = priority;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Huffman {
public:
    Node *head;

    Huffman() {
        head = NULL;
    }

    void enqueue(char val, int priority) {
        Node *newNode = new Node(val, priority);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }

    void enqueue(Node *intNode) {
        if (head == NULL) {
            head = intNode;
            return;
        }
        Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = intNode;
    }

    Node *dequeue() {
        if (head == NULL) {
            return NULL;
        }
        int maxPriority = INT_MAX;
        Node *ptr = head;

        while (ptr != NULL) {
            if (ptr->priority < maxPriority)
                maxPriority = ptr->priority;
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr->priority != maxPriority)
            ptr = ptr->next;

        detachFromQueue(ptr);
        return ptr;
    }

    void detachFromQueue(Node *delPtr) {
        if (head == delPtr) {
            head = head->next;
            return;
        }
        Node *ptr = head;
        while (ptr->next != delPtr)
            ptr = ptr->next;
        ptr->next = delPtr->next;
        delPtr->next = NULL;
    }

    int countNodes() {
        Node *ptr = head;
        int count = 0;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    void ConvertToTree() {
        while (countNodes() > 1) {
            Node *left = dequeue();
            Node *right = dequeue();
            Node *internalNode = new Node('#', left->priority + right->priority);
            internalNode->left = left;
            internalNode->right = right;
            enqueue(internalNode);
        }
    }

    void Encode(Node *root, string str) {
        if (root == NULL)
            return;
        if (root->data != '#') {
            encodedString += str;
            cout << root->data << ": " << str << endl;
        }
        Encode(root->left, str + "0");
        Encode(root->right, str + "1");
    }

    void Decode(string encodedString) {
        string decodedString;
        Node *ptr = head;
        for (int i = 0; i < encodedString.size(); i++) {
            if (encodedString[i] == '0')
                ptr = ptr->left;
            else
                ptr = ptr->right;

            if (ptr->left == NULL && ptr->right == NULL) {
                for (int i = 0; i < ptr->priority; i++)
                    decodedString += ptr->data;
                ptr = head;
            }
        }
        cout << "Decoded string: " << decodedString;
    }
};

int main() {
    Huffman q;
    q.enqueue('A', 45);
    q.enqueue('B', 13);
    q.enqueue('C', 12);
    q.enqueue('D', 16);
    q.enqueue('E', 9);
    q.enqueue('F', 5);
    
    q.ConvertToTree();
    
	cout << "Huffman Codes for each character: " << endl;
    q.Encode(q.head, "");
    
	
	cout << "Encoded string: " << encodedString << endl;
    q.Decode(encodedString);
    
	
	return 0;
}

