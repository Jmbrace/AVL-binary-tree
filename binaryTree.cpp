#include "binaryTree.h"
#include <string>
#include <algorithm>

binaryTree::binaryTree()
{
  root = NULL;
}

binaryTree::~binaryTree()
{
  delete root;
}

bool binaryTree::addWord(const std::string word)
{
   bool inserted = false;
   insert(word, root, inserted);
   return inserted;
}

int binaryTree::getNumberOfWords() const
{
  return root->size;
}

std::string binaryTree::getWordOfDay(const int i)
{
  return findWord(i, root);
}

bool binaryTree::validRank(const int rank) const
{
  return (rank>0 && rank<=root->size);
}

binaryTree::Node::Node()
{
  word = "";
  leftChild = NULL;
  rightChild = NULL;
}

binaryTree::Node::Node(std::string theWord, Node* left, Node* right)
{
  word = theWord; 
  leftChild = left;
  rightChild = right;
}

binaryTree::Node::~Node()
{
  if(rightChild!=NULL)
    delete rightChild;
  if(leftChild!=NULL)
    delete leftChild;
}

void binaryTree::insert(std::string word, Node*& root, bool& inserted)
{
  if(root == NULL)
  { 
    inserted = true;
    root = new Node(word, NULL,NULL);
  }
  else if(word<root->word)
  {
    insert(word, root->leftChild, inserted);
    if(height(root->leftChild)-height(root->rightChild)==2)
    {
        if(word<root->leftChild->word)
        {
         rightRotate(root);
        }
        else
        {
         leftRotate(root->leftChild);
         rightRotate(root);
        }
    }
  }
  else if(word>root->word)
  {
    insert(word, root->rightChild, inserted);
    if(height(root->rightChild)-height(root->leftChild)==2)
    {
      if(root->rightChild->word < word)
      {
        leftRotate(root);
      }
      else
      {
        rightRotate(root->rightChild);
        leftRotate(root);
      }
    }
  }
  root->height = std::max(height(root->leftChild), height(root->rightChild)) + 1;
  root->size = 1 + size(root->leftChild) + size(root->rightChild);
}

int binaryTree::size(Node* root)
{
  return root == NULL ? 0 : root->size;
}

int binaryTree::height(Node* root)
{
  return root == NULL ? 0 : root->height;
}

std::string binaryTree::findWord(const int i, Node* root)
{
  int m = 1 + size(root->leftChild);
  if(i==m)
    return root->word;
  if(m>i)
    return findWord(i, root->leftChild);
  else
    return findWord(i-m, root->rightChild);
}

void binaryTree::leftRotate(Node* &k2)
{
  Node* k1 = k2->rightChild;
  k2->rightChild = k1->leftChild;
  k1->leftChild = k2;
  k2->height = std::max(height(k2->leftChild), height(k2->rightChild)) + 1;
  k1->height = std::max(height(k1->leftChild), height(k1->rightChild)) + 1;
  k1->size = 1 + size(k1->leftChild) + size(k1->rightChild);
  k2->size = 1 + size(k2->leftChild) + size(k2->rightChild);
  k2 = k1;
}

void binaryTree::rightRotate(Node* &k2)
{
  Node* k1 = k2->leftChild;
  k2->leftChild = k1->rightChild;
  k1->rightChild = k2;
  k2->height = std::max(height(k2->leftChild), height(k2->rightChild)) + 1;
  k1->height = std::max(height(k1->leftChild), height(k1->rightChild)) + 1;
  k1->size = 1 + size(k1->leftChild) + size(k1->rightChild);
  k2->size = 1 + size(k2->leftChild) + size(k2->rightChild);
  k2 = k1;
}
