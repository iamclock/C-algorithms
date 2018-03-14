#ifndef BABM_H
#define BABM_H

#include <iostream>
#include <fstream>


#include "TreeForBaBM.h"
//#include "Matrix.h"
#include "SalesmanNode.h"




using std::cout;
using std::cin;
using std::ifstream;



class Salesman_problem_solver{
public:
	virtual Tour find_best_tour(const CostMatrix &matr) const=0;
};







class Branch_n_bounds_method: public Salesman_problem_solver{
	void BaBM(SalesmanNode &step); //переименовать
	SalesmanNode *to_y(SalesmanNode &step, unsigned int k, unsigned int l, bool &check);
	void dellock(SalesmanNode &cur_node, unsigned int k, unsigned int l);
	SalesmanNode *to_x(SalesmanNode &step, unsigned int k, unsigned int l, bool &check);
	SalesmanNode &privedenie(SalesmanNode &step, bool &check, Tree &roads);
public:
	//конструктор будет порождать объект от матрицы и будет вызываться из main
	//от файла
	//Branch_n_bounds_method(){}
	virtual Tour find_best_tour(const CostMatrix &matr) const; 
	
	
	
	
	
	
};






#endif