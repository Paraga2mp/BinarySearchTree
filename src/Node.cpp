
#include "Node.h"

Node::Node() {

    this->word = "0";
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
}

Node::~Node() {

    delete left;
    delete right;
}
