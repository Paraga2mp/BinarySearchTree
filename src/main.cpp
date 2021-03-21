#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

// prototypes
void ReadDictionary(BST &bst, string &filename);
string ReadFileToCheck(string &filename);
void CheckError(BST &bst, string &filename);


int main() {

    BST bst;
    string dictionary = "..\\tests\\dictionary.txt";
    ReadDictionary(bst,dictionary);

    string filename = "..\\tests\\test.txt";
    string filename2 = "..\\docs\\sample.txt";

    cout << "File: " << filename << endl;
    CheckError(bst,filename);

    cout << endl;

    cout << "File: " << filename << endl;
    CheckError(bst,filename2);

    cout << endl;

    cout << bst;



    return 0;
}

// read the file content and insert the content into a binary tree
void ReadDictionary(BST &bst, string &filename) {

    string word;
    ifstream dictionary(filename);

    if (dictionary.is_open()) {
        while (getline(dictionary, word)) {
            bst.InsertNode(word);
        }
        dictionary.close();
    }
    else {
        cout << "Could not open file to read" << endl;
    }
}

// read the file content and store into a string
string ReadFileToCheck(string &filename) {

    string document;
    string documentSegment;
    ifstream file(filename);

    if (file.is_open()) {
        while (getline(file, documentSegment)) {
            document += documentSegment;
        }
        file.close();
    }
    else {
        cout << "Could not open file to read" << endl;
    }
    return document;
}

// check the tree for the words in the file and if the words from the file
// are not found in the tree print the words to the console
void CheckError(BST &bst, string &filename) {

    string fileData;
    fileData = ReadFileToCheck(filename);
    string words[1000];
    int j = 0;

    string newWord = "";

    for(int i = 0; i < fileData.length(); i++) {
        if (fileData[i] >= 'A' && fileData[i] <= 'Z') {
            newWord += fileData[i];
        }
        else if(fileData[i] >= 'a' && fileData[i] <= 'z') {
            newWord += fileData[i];
        }
        else if(!newWord.empty()) {
            words[j] = newWord;
            newWord = "";
            j++;
        }
    }

    int totalError = 0;

    // search for every words of the words array the tree, if not found print the word
    for(int i = 0; i < j; i++) {
        if(!bst.SearchResult(words[i])) {
            if(totalError == 0) {
                cout << "Errors found in your file" << endl;
            }
            cout << words[i] << endl;
            totalError++;
        }
    }
    if(totalError == 0) {
        cout << "No error found." << endl;
    }
}
