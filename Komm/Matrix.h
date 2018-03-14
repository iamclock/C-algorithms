#ifndef MATRIX_BaBM_H
#define MATRIX_BaBM_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <assert.h>



using std::cout;
using std::cin;
using std::ifstream;



class Edge: public std::pair<unsigned int, unsigned int>{
public:
	
	
	
	Edge(unsigned int i, unsigned int j):std::pair<unsigned int, unsigned int>(i, j){}
	
	
	
	
};








class CostMatrix{
public:
	CostMatrix(unsigned int n=0);
	~CostMatrix();
	void print();
	Edge find_edge_for_branching();
	void max_among_zeros(unsigned int);
	int &operator ()(unsigned int i, unsigned int j);
	CostMatrix &operator =(CostMatrix &a);
	//возвращает до length+1
	CostMatrix(/*const*/ CostMatrix &m);
	void MinStr();
	void MinCol();
	bool all_crossed();
	void Read(ifstream &f);
	unsigned int size();
private:
	int min_in_str_excluding_current(unsigned int str_num, unsigned int current);
	int min_in_col_excluding_current(unsigned int current, unsigned int col_num);
	int **matr;
	unsigned int matr_length;
};

#endif