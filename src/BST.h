
#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H

#include "Node.h"

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
    Node* Insert(Node* node, string key);
    Node* Search(Node* root, string key);

    string ConvertToLowerCase(string &str);
    friend bool operator < (string first,string second);
    friend bool operator > (string first,string second);

    friend ostream& operator<<(ostream& output, BST& bst);

    string GetWord(Node *node);
    friend ostream& operator<<( ostream &output, BST &bst );
    void InsertNode(string &key);

    bool SearchResult(string &key);

};


#endif //ASSIGNMENT_3_BST_H
