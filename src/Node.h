
#ifndef ASSIGNMENT_3_NODE_H
#define ASSIGNMENT_3_NODE_H

#include <string>

using namespace std;

class Node {

public:
    string word;
    Node *left;
    Node *right;
    int height;

    Node();
    virtual ~Node();
};

#endif //ASSIGNMENT_3_NODE_H
