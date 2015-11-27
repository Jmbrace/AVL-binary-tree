
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <string>

class binaryTree{

public:

	binaryTree();
	~binaryTree();
	bool addWord(const std::string word);//adds a node to tree with word as the data
	int getNumberOfWords() const;//returns the size of the root
	std::string getWordOfDay(const int x);//returns the xth word in tree
    bool validRank(const int rank) const;//determines if a rank is between 1 and rank of last word in tree
private:

	class Node{
		friend class binaryTree;
	public:
        Node();
        Node(std::string theWord, Node* left, Node* right);
        ~Node();
    private:
    	Node* leftChild;
    	Node* rightChild;
        std::string word;
    	int size;
    	int height;
	};
    void insert(std::string word, Node*& root, bool& inserted);
    Node* root;
    int size(Node* root);
    int height(Node* root);
    std::string findWord(int i, Node* root);
    void leftRotate(Node* &k2);
    void rightRotate(Node* &k2);
};

#endif