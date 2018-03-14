#ifndef BINTREE_H
#define BINTREE_H



#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstddef> //have nullptr | -std=c++0x|
#include <iomanip>
#include <queue>

class Node{
public:
	int key;
	Node *left;
	Node *right;
	Node(int val=0):key(val),left(nullptr),right(nullptr){}
	virtual ~Node(){}
	virtual void Print(Node *a){}
	//virtual Node &operator =(Node &a);
};


class BinTree{
private:
	unsigned int nodes;
	Node *root;
	unsigned int maxH;

public:	
	BinTree(int k=0);
	~BinTree();
	Node*	SearchKey(int k);
	void AddNode(int val=0);
	void DeleteSubtree(Node *a);
	void Print();
	unsigned int getH();
	void PrintSubTree(Node *cur_node);
	void PrintBFS();
private:
	void HeightBFS(Node* a, std::queue<Node *> &queue);
	void Print(Node *a, unsigned int sh=0);
	Node* SearchKey(int k, Node *a);
	void CalculateHeight(Node *a, unsigned int k);
	void AddNode(Node *a, int val=0);
};


#endif
