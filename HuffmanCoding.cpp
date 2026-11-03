
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure of a Huffman Tree Node
struct Node {
    char ch;
    int freq;

    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare function for Min Priority Queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman Codes
void printCodes(Node* root, string code) {

    if (root == NULL)
        return;

    // If leaf node, print character and code
    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Build Huffman Tree
void huffmanCoding(char characters[], int frequencies[], int n) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into priority queue
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(characters[i], frequencies[i]);
        pq.push(newNode);
    }

    // Build Huffman Tree
    while (pq.size() > 1) {

        // Extract two minimum frequency nodes
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create a new internal node
        Node* newNode = new Node('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        // Insert the new node back
        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    cout << "Huffman Codes:\n";
    printCodes(root, "");
}

int main() {

    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    int frequencies[] = {5, 9, 12, 13, 16, 45};

    int n = 6;

    huffmanCoding(characters, frequencies, n);

    return 0;
}
