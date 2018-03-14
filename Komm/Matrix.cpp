#include "Matrix.h"


//проверка идёт до элемента length+1






CostMatrix::CostMatrix(unsigned int n){
	if(n==0){
		matr=nullptr;
		matr_length=n;
		return;
	}
	matr_length=n;
	matr=new int*[matr_length+1];
	for(unsigned int i=0; i<matr_length+1; ++i){
		matr[i]=new int[matr_length+1];
	}
}











CostMatrix::~CostMatrix(){
	if(!matr){
		return;
	}
	for(unsigned int i=0; i<matr_length+1; ++i){
		delete []matr[i];
	}
	delete []matr;
	matr=nullptr;
}





unsigned int CostMatrix::size(){
	return matr_length;
}






void CostMatrix::print(){
	cout << "Матрица: " << "\n";
	for(unsigned int i=0; i<matr_length+1; ++i){
		for(unsigned int j=0; j<matr_length+1; ++j){
			cout << std::setw(5);
			cout << matr[i][j];// << " ";
		}
		cout << "\n";
	}
}



int CostMatrix::min_in_str_excluding_current(unsigned int i, unsigned int j){
	int min=INT_MAX;
	bool check=false;
	for(unsigned int k=0; k<matr_length; ++k){
		if((matr[i][k]<min) && (matr[i][k]!=-1) && (k!=j)){
			min=matr[i][k];
			check=true;
		}
	}
	if(check)
		return min;
	return 0;
}







int CostMatrix::min_in_col_excluding_current(unsigned int i, unsigned int j){
	int min=INT_MAX;
	bool check=false;
	for(unsigned int k=0; k<matr_length; ++k){
		if((matr[k][j]<min) && (matr[k][j]!=-1) && (k!=i)){
			min=matr[k][j];
			check=true;
		}
	}
	if(check)
		return min;
	return 0;
}



Edge CostMatrix::find_edge_for_branching(){
	int max=-1, temp;
	unsigned int k, l;
	k=l=std::numeric_limits<unsigned int>::max();
	for(unsigned int i=0; i<matr_length; ++i){
		for(unsigned int j=0; j<matr_length; ++j)
			if(matr[i][j]==0){
				temp=min_in_str_excluding_current(i, j);
				temp+=min_in_col_excluding_current(i ,j);
				if(max<temp){
					max=temp;
					k=i;
					l=j;
				}
			}
	}
	assert(k!=std::numeric_limits<unsigned int>::max() && l!=std::numeric_limits<unsigned int>::max());
	return Edge(k, l);
}


bool CostMatrix::all_crossed(){
	for(unsigned int i=0; i<matr_length; ++i)
		for(unsigned int j; j<matr_length; ++j)
			if(matr[i][j]!=-1) return true;
	return false;
}




void CostMatrix::max_among_zeros(unsigned int i){
	int max=-1, temp;
	for(unsigned int j=0; j<matr_length; ++j)
		if(matr[i][j]==0){
			temp=this->min_in_str_excluding_current(i, j);
			temp+=this->min_in_col_excluding_current(i ,j);
			if(max<temp) max=temp;
		}
	matr[i][matr_length]=max;
}






void CostMatrix::MinStr(){
	int minstr=INT_MAX;
	unsigned int check;
	for(unsigned int i=0; i<matr_length; ++i){
		check=0;
		for(unsigned int j=0; j<matr_length; ++j){
			if((matr[i][j]<minstr)&&(matr[i][j]!=-1)) minstr=matr[i][j];
			if(matr[i][j]==-1) ++check;
		}
		if(check==matr_length) minstr=-1;
		matr[i][matr_length]=minstr;
		minstr=INT_MAX;
	}
}





void CostMatrix::MinCol(){
	int mincol=INT_MAX;
	unsigned int check;
	for(unsigned int j=0; j<matr_length; ++j){
		check=0;
		for(unsigned int i=0; i<matr_length; ++i){
			if((mincol>matr[i][j])&&(matr[i][j]!=-1)) mincol = matr[i][j];
			if(matr[i][j]==-1) ++check;
		}
		if(check==matr_length) mincol=-1;
		matr[matr_length][j]=mincol;
		mincol=INT_MAX;
	}
	
	
}




int& CostMatrix::operator ()(unsigned int i, unsigned int j){
	if(i<matr_length+1&&j<matr_length+1)
		return matr[i][j];
	cout << "one of the indexes out of range\n";
	throw "Out of Range\n";
}


CostMatrix &CostMatrix::operator =(CostMatrix &a){
	if(matr_length!=a.size()){
		cout << "This must contain reallocate memory, but this is not yet ready. Stay tuned\n";
		throw "Memory allocation not yet ready";
	}
	for(unsigned int i=0; i<matr_length+1; ++i)
		for(unsigned int j=0; j<matr_length+1; ++j)
			matr[i][j]=a(i, j);
	return *this;
}


CostMatrix::CostMatrix(/*const*/ CostMatrix &m){
	matr_length=m.size();
	matr=new int*[matr_length+1];
	for(unsigned int i=0; i<matr_length+1; ++i)
		matr[i]=new int[matr_length+1];
	for(unsigned int i=0; i<matr_length+1; ++i)
		for(unsigned int j=0; j<matr_length+1; ++j)
			matr[i][j]=m(i, j);
}



void CostMatrix::Read(ifstream &f){
	if(!matr){
		cout << "errorka\n";
		throw "Can't Read to matrix object cause it's null";
	}
	int x;
	for(unsigned int i=0; i<matr_length; ++i){
		for(unsigned int j=0; j<matr_length; ++j){
			f >> x;
			if(i==j) matr[i][j]=-1;
			else matr[i][j]=x;
		}
	}
	print();
}