#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;
class Node {
public:
    int freq;
    char letter;
    Node* left, * right;
    Node(char letter, int freq) {
        this->letter = letter;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }

};

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}
void Heapify(vector<Node*>& heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap.size() && heap[left]->freq < heap[smallest]->freq) {
        smallest = left;
    }
    if (right < heap.size() && heap[right]->freq > heap[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swapNodes(&heap[smallest], &heap[i]);
        Heapify(heap, smallest);
    }

}

Node* extractMin(vector<Node*>& heap) {
    Node* temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    Heapify(heap, 0);
    return temp;
}
void insert(vector<Node*>& heap, Node* n) {
    heap.push_back(n);
    int i = heap.size() - 1;
    while (i >= 0 && heap[i]->freq > heap[(i - 1) / 2]->freq) {
        swapNodes(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void prioritize(vector<Node*>& heap) {
    int maxIdx = heap.size() - 1;
    for (int i = (maxIdx - 1) / 2; i >= 0; i--) {
        Heapify(heap, i);
    }
}
bool isLeaf(Node* n) {
    return !(n->right || n->left);
}
vector<Node*> createHeap(vector<char>& item, vector<int>& freq) {
    vector<Node*> heap;
    for (int i = 0; i < item.size(); i++) {
        Node* n = new Node(item[i], freq[i]);
        heap.push_back(n);
    }
    prioritize(heap);
    return heap;
}

vector<Node*> buildTree(vector<char>& item, vector<int>& freq) {
    Node* left, * right, * top;
    left = nullptr;
    right = nullptr;
    top = nullptr;
    vector<Node*> heap = createHeap(item, freq);

    while (heap.size() != 1) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = new Node('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(heap, top);
    }
    return heap;
}
void printHuffman(Node* root, vector<int>& arr, int top) {
    if (root->left) {
        arr.push_back(0);
        printHuffman(root->left, arr, top + 1);
    }
    if (root->right) {
        arr.push_back(1);
        printHuffman(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        cout << root->letter << " |";
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
}
void printArray(vector<int>& vec) {
    cout << "Array : " << endl;
    for (auto i : vec) {
        cout << i << endl;
    }
    cout << endl;
}
int main() {
    vector<char> letter = { 'A', 'B', 'C', 'D' };
    vector<int> freq = { 5,1,6,3 };
    cout << "Char | Huffman code";
    cout << "\n-----------------\n";
    vector<Node*> root = buildTree(letter, freq);
    vector<int> arr;
    printHuffman(root[0], arr, 0);

}
