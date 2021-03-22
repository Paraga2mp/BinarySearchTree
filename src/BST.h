
#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H

#include "Node.h"

typedef Node* NodePtr;

class BST {

private:
    Node *root;

public:
    BST();
    virtual ~BST();
    int Max(int num1, int num2);
    int Height(Node *node);
    int GetBalance(Node *node);

    Node *RotateRight(Node *y);
    Node *RotateLeft(Node *x);
    Node* Insert(Node* node, string word);
    void InsertNode(string &word);
    Node* Search(Node* root, string word);
    bool SearchResult(string &word);

    friend bool operator < (string first,string second);
    friend bool operator > (string first,string second);
    friend ostream& operator<<(ostream& output, BST& bst);

    void PrintTree(ostream& output, NodePtr& node, int indent, ofstream& outFile);
    string GetWord(Node *node);
    string ConvertToLowerCase(string &str);

    void ReadDictionary(BST &bst, string &filename);
    string ReadFileToCheck(string &filename);
    void CheckError(BST &bst, string &filename);

};


#endif //ASSIGNMENT_3_BST_H
