#include <iostream>
#include "BST.h"

using namespace std;

int main() {

    BST bst;
    string dictionary = "..\\tests\\dictionary.txt";
    bst.ReadDictionary(bst,dictionary);

    string filename = "..\\tests\\test.txt";
    string filename2 = "..\\docs\\sample.txt";

    cout << "File: " << filename << endl;
    bst.CheckError(bst,filename);
    cout << endl;

    cout << "File: " << filename2 << endl;
    bst.CheckError(bst,filename2);
    cout << endl;

    cout << bst;


    return 0;
}

