#include "BaBM.h"

//создать объект матрицу CostMatrix
//проследить за спец-рами const
//нужен ли конструктор от указ-ля
//обойтись конструктором копирования
//передавать ссылки
//









void Branch_n_bounds_method::dellock(SalesmanNode &cur_node, unsigned int k, unsigned int l){
	cur_node.matr(l, k)=-1;
	unsigned int check=0;
	for(unsigned int i=0; i<cur_node.tour.source.size(); ++i)
		if(l==cur_node.tour.source[i]&&check<cur_node.tour.source.size()){
			l=cur_node.tour.stock[i];
			i=0;
			++check;
		}
	check=0;
	for(unsigned int i=0; i<cur_node.tour.source.size(); ++i)
		if(k==cur_node.tour.stock[i]&&check<cur_node.tour.source.size()){
			k=cur_node.tour.source[i];
			i=0;
			++check;
		}
	if(cur_node.tour.source.size()!=cur_node.matr.size()-1)
		cur_node.matr(l, k)=-1;
	//cur_node.matr[k][l]=-1;
}



Tour Branch_n_bounds_method::find_best_tour(ifstream &f) const{
	Tree roads;
	Node *Fposition;
	roads.setRoot(&Fposition);
	Fposition.matr.Read(Matrix);
	
	//Fposition.tour = Tour(Fposition.matr.size());
	//f.close();
	TaBM(Fposition);
	MinTour=&privedenie(Fposition, check, roads); //
	
	
	
	
	
}




void Branch_n_bounds_method::TaBM(SalesmanNode &step){
	int H=0;
	step.matr.MinStr();
	for(unsigned int i=0; i<step.matr.size(); ++i){
		for(unsigned int j=0; j<step.matr.size(); ++j)
			if(step.matr(i, j)!=-1)
				step.matr(i, j)-=step.matr(i, step.matr.size());
		if(step.matr(i, step.matr.size())!=-1)
			H+=step.matr(i, step.matr.size());
	}
	step.matr.print();
	step.matr.MinCol();
	for(unsigned int j=0; j<step.matr.size(); ++j){
		for(unsigned int i=0; i<step.matr.size(); ++i)
			if(step.matr(i, j)!=-1)
				step.matr(i, j)-=step.matr(step.matr.size(), j);
		if(step.matr(step.matr.size(), j)!=-1)
			H+=step.matr(step.matr.size(), j);
	}
	//print(step);
	step.cost=step.cost+H;
	cout << "H= " << step.cost << '\n';
	
	/*
	for(unsigned int i=0; i<step.matr.size(); ++i)
		step.matr.max_among_zeros(i);
	*/
	//print(step);
}




SalesmanNode *Branch_n_bounds_method::to_y(SalesmanNode &step, unsigned int k, unsigned int l, bool &check){
	SalesmanNode *y=new SalesmanNode(step);
	step.left=dynamic_cast <Node*> (y);
	y->matr(k, l)=-1;
	cout << "Матрица Y до TaBM:\n";
	y->matr.print();
	TaBM(*y);
	cout << "Матрица Y после TaBM:\n";
	y->matr.print();
	//temp=&y;
	return y;
}






SalesmanNode *Branch_n_bounds_method::to_x(SalesmanNode &step, unsigned int k, unsigned int l, bool &check){
	SalesmanNode *x=new SalesmanNode(step);
	step.right=dynamic_cast <Node*> (x);
	x->tour.AddVertex(k,l);
	//поменять удаление строк и столбцов
	for(unsigned int i=0; i<x->matr.size()+1; ++i){
		for(unsigned int j=0; j<x->matr.size()+1; ++j){
			if(i==x->matr.size()) x->matr(i, j)=0;
			else{
				if((i==k)||(j==l))
					x->matr(i, j)=-1;
				else
					x->matr(i, j)=step.matr(i, j);
			}
		}
		x->matr(i, x->matr.size())=0;
	}
	dellock(*x, k, l);
	cout << "Матрица X до TaBM:\n";
	x->matr.print();
	TaBM(*x);
	cout << "Матрица X после TaBM:\n";
	x->matr.print();
	if(x->tour.source.size()==x->matr.size()){
		check=true;
	}
	//temp=&x;
	return x;
}





SalesmanNode &Branch_n_bounds_method::privedenie(SalesmanNode &step, bool &check, Tree &roads){
	SalesmanNode *stepmin=nullptr;
	SalesmanNode *X=nullptr;
	SalesmanNode *Y=nullptr;
	/*
	bool all_visited=false;
	unsigned int k, l;
	for(unsigned int i=0; i<step.matr.size(); ++i)
		if(step.matr(i, step.matr.size())>max){
			max=step.matr(i, step.matr.size());
			k=i;
		}
	if(max>-1)
		for(l=0; l<step.matr.size(); ++l)
			if(step.matr(k, l)==0){
				int temp=step.matr.min_in_str_excluding_current(k, l);
				temp+=step.matr.min_in_col_excluding_current(k, l);
				if(temp==max) break;
			}
	*/
	bool all_visited=step.matr.all_crossed();
	Edge edge=step.matr.find_edge_for_branching();
	if( all_visited && !check ) return *stepmin;
	if( all_visited && check ) return step;
	cout << "STEEEEEEEEEEEEEEEEEEPPPP\n";
	step.matr.print();
	if(!check){
		if(!X){
			X=to_x(step, k, l, check);
			Y=to_y(step, k, l, check);
			stepmin=roads.search_min(min(X,Y));
			if(stepmin->cost<min(X,Y)->cost){
				*stepmin=privedenie(*stepmin, check, roads);
			}
			else
				*stepmin=privedenie(*min(X,Y), check, roads);
			if(!check){
				stepmin=roads.search_min(min(X,Y));
				*stepmin=privedenie(*stepmin, check, roads);
			}
		}
		else
			*stepmin=privedenie(*Y, check, roads);
	}
	return *stepmin;
}


