#ifndef TREE_BaBM_H
#define TREE_BaBM_H


#include <iomanip>
#include "SalesmanNode.h"










class Tree{
public:
	void setRoot(SalesmanNode *a);
	Tree();
	//SalesmanNode *RetRoot();
	~Tree();
	bool empty(); //Проверка на пустое дерево(если отсутствует корень)
	void Print();
	SalesmanNode *search_min(SalesmanNode *b);
private:
	SalesmanNode *DFS(SalesmanNode *u, SalesmanNode *b);
	SalesmanNode *root;
	void DeleteSTree(SalesmanNode *a); // Сделано
	void Print(SalesmanNode *a, unsigned int sh=0);
};

#endif