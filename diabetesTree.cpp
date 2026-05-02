#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string data;
    vector<Node*> children;

    Node(string value) {
        data = value;
    }
};

void printTree(Node* root, int level = 0) {
    if (root == nullptr) return;

    for (int i = 0; i < level; i++) {
        cout << "  ";
    }

    cout << root->data << endl;

    for (Node* child : root->children) {
        printTree(child, level + 1);
    }
}

int main() {
    Node* root = new Node("Diabetes Supplies");

    Node* monitoring = new Node("Monitoring");
    Node* insulin = new Node("Insulin");
    Node* emergency = new Node("Emergency");

    root->children.push_back(monitoring);
    root->children.push_back(insulin);
    root->children.push_back(emergency);

    monitoring->children.push_back(new Node("CGM"));
    monitoring->children.push_back(new Node("Glucometer"));

    insulin->children.push_back(new Node("Rapid Acting"));
    insulin->children.push_back(new Node("Long Acting"));

    emergency->children.push_back(new Node("Candy"));
    emergency->children.push_back(new Node("Glucagon"));

    cout << "Tree Traversal:\n";
    printTree(root);

    return 0;
}