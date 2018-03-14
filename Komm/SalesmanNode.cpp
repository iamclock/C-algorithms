#include "SalesmanNode.h"




Tour::Tour(unsigned int n){
	source.reserve(n);
	stock.reserve(n);
}


void Tour::AddVertex(unsigned int i, unsigned int j){
	source.push_back(i);
	stock.push_back(j);
}



void Tour::Print(){
	for(unsigned int i=0; i<source.size(); ++i)
		cout << source[i] << '-' << stock[i] << '\n';
}







SalesmanNode::~SalesmanNode(){
	left=nullptr;
	right=nullptr;
	cost=0;
}





SalesmanNode *min(SalesmanNode *a, SalesmanNode *b){
	if(a->cost==b->cost) return a;
	if(a->cost<b->cost) return a;
	return b;
}




SalesmanNode &SalesmanNode::operator =(SalesmanNode &a){
	if(this==&a) return *this;
	cost=a.cost;
	tour=a.tour;
	matr=a.matr;
	//left=a.left;
	//right=a.right;
	//key=a.key;
	return *this;
}




/*
void SalesmanNode::Print(){
	SalesmanNode *temp=nullptr;
	temp=dynamic_cast <SalesmanNode*> (a);
	cout << temp->cost << '\n';
}
*/
