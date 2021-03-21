
#include <iomanip>
#include <fstream>
#include "BST.h"

using namespace std;
typedef Node* NodePtr;


BST::BST() {

    root = NULL;
}

BST::~BST() {

    delete root;
}

//Function to find greater number.
int BST::Max(int firstNum, int secondNum) {

    return (firstNum > secondNum) ? firstNum : secondNum;
}

//function to find height of branch.
int BST::Height(Node *node) {

    if (node == NULL) {
        return 0;
    }
    return node->height;
}

//Function for getting key value.
string BST::GetWord(Node *node) {

    if (node == NULL) {
        return 0;
    }
    return node->word;
}

//Function to check if tree is balanced.
int BST::GetBalance(Node *node) {

    if (node == NULL) {
        return 0;
    }
    return Height(node->left) - Height(node->right);
}

//Function to convert Uppercase letter to lowercase.
string BST::ConvertToLowerCase(string &str) {

    string newString;

    for(int i=0; i < str.length(); i++) {
        newString += tolower(str[i]);
    }
    return newString;
}

//Function to right rotate the imbalanced tree
Node* BST::RotateRight(Node *node) {

    Node *subTree = node->left;
    Node *leaf = subTree->right;

    // Perform rotation
    subTree->right = node;
    node->left = leaf;

    // Update heights
    node->height = Max(Height(node->left),
                       Height(node->right)) + 1;
    subTree->height = Max(Height(subTree->left),
                          Height(subTree->right)) + 1;

    // Return new root
    return subTree;
}

//Function to left rotate the imbalanced tree
Node* BST::RotateLeft(Node *node) {

    Node *subTree = node->right;
    Node *leaf = subTree->left;

    // Perform rotation
    subTree->left = node;
    node->right = leaf;

    // Update heights
    node->height = Max(Height(node->left),
                       Height(node->right)) + 1;
    subTree->height = Max(Height(subTree->left),
                          Height(subTree->right)) + 1;

    // Return new root
    return subTree;
}

// operator to compare sequential letters of two strings, is less than or not
bool operator < (string firstStr,string secondStr) {

    int i = 0;
    int n = firstStr.length() < secondStr.length() ? firstStr.length() : secondStr.length();

    while(i < n) {
        if(tolower(firstStr[i]) != tolower(secondStr[i])) {
            return tolower(firstStr[i]) < tolower(secondStr[i]);
        }
        i++;
    }

    return firstStr.length() < secondStr.length();
}

// operator to compare sequential letters of two strings, is greater than or not
bool operator > (string firstStr, string secondStr) {

    int i = 0;
    int n = firstStr.length() < secondStr.length() ? firstStr.length() : secondStr.length();

    while(i < n) {
        if(tolower(firstStr[i]) != tolower(secondStr[i])) {
            return tolower(firstStr[i]) > tolower(secondStr[i]);
        }
        i++;
    }

    return firstStr.length() > secondStr.length();
}


// Function to call the recursive function to insert a word in the tree
// rooted with given node
void BST::InsertNode(string &key) {

    root = Insert(root,key);
}

//Recursive function to insert a word in the tree rooted with node and
//returns the new root of the subtree.
Node* BST::Insert(Node* node, string word) {

    // insert the word into the tree
    if (node == NULL) {
        Node *newNode = new Node();
        newNode->word = word;
        return newNode;
    }
    // determine where to insert, left ot right to the node
    if (word < GetWord(node)) {
        node->left = Insert(node->left, word);
    }
    else if (word > GetWord(node)) {
        node->right = Insert(node->right, word);
    }
    else {
        // equal words are not allowed to insert
        return node;
    }

    // update the height of the parent node
    node->height = 1 + Max(Height(node->left),Height(node->right));

    // get the balance value to check whether the node is balance or not
    // the node is balanced if int balance value = {-1, 0, 1}, otherwise imbalance
    int balance = GetBalance(node);

    // if the node becomes imbalance, then there are 4 cases
    // Left Left Case
    if (balance > 1 && word < GetWord(node->left)) {
        return RotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && word > GetWord(node->right)) {
        return RotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && word > GetWord(node->left)) {
        node->left = RotateLeft(node->left);
        return RotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && word < GetWord(node->right)) {
        node->right = RotateRight(node->right);
        return RotateLeft(node);
    }

    return node;
}

//Function to search a word from the tree.
bool BST::SearchResult(string &key) {

    return Search(root, ConvertToLowerCase(key)) != NULL;
}

//Recursive function to search a word from the tree
Node* BST::Search(Node* root, string key) {

    if (root == NULL || root->word == key)
        return root;

    // word is greater than root's word
    if (root->word < key) {
        return Search(root->right, key);
    }

    // word is less than root's word
    return Search(root->left, key);
}

void PrintTree(ostream& output, NodePtr& node, int indent, ofstream& outFile) {
//    indent += 8;
    if (node != nullptr) {
//        indent += 8;
        PrintTree(output, node->right, indent + 16, outFile);
        output << setw(indent) << node->word << endl;
        outFile << setw(indent) << node->word << endl;
        PrintTree(output, node->left, indent + 16, outFile);
    }
}

ostream& operator<<(ostream& output, BST& bst) {
    ofstream outputFile;
    string outPath = "..\\output\\BSTOutput.txt";
    outputFile.open(outPath);
    PrintTree(output, bst.root, 0, outputFile);
    return output;
}


