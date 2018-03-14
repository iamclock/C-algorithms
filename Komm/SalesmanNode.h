#ifndef NODE_BaBM_H
#define NODE_BaBM_H



#include "BinTree (QueueArray).h"
#include "Matrix.h"
#include <vector>





using std::vector;



class Tour{
public:
	vector<unsigned int> source;
	vector<unsigned int> stock;
	Tour(unsigned int n);
	void AddVertex(unsigned int i, unsigned int j);
	void Print();
};


class SalesmanNode:public Node{
public:
	unsigned int cost;
	Tour tour;
	CostMatrix matr;
	SalesmanNode(unsigned int n):Node(), cost(0), tour(n), matr(n){}
	SalesmanNode(/*const*/ SalesmanNode &b):Node(), 
	cost(b.cost), tour(b.tour), matr(b.matr){}
	//virtual void Print();
	SalesmanNode &operator =(SalesmanNode &a);
	~SalesmanNode();
};

SalesmanNode *min(SalesmanNode *a, SalesmanNode *b);





#endif