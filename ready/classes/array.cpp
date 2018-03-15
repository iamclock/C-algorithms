#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>



template <class A>
class Array{
public:
  Array(int n=10);
  Array(int n, A Fill);
  ~Array();
  Array &operator =(const Array &a);
  int &operator [](int index);
public:
  
  void add(A element);
  void insert(int index, A element);
  void remove(int index);
  void resize(int n);
  int size()const;
private:
  A *mem;
  int vol, max_vol;
};
//::::::::::::::::::::::::::::::::::::::
template <class A>
Array<A>::Array(int n){
  vol=n;
  max_vol=vol+3;
  mem=new int[max_vol];
}

template <class A>
Array<A>::Array(int n, A Fill){
  int i;
  vol=n;
  max_vol=vol+3;
  mem=new int[max_vol];
  for(i=0; i<vol; i++) mem[i]=Fill;
}

template <class A>
Array<A>::~Array() {delete []mem;}


template <class A>
Array<A> &Array<A>::operator =(const Array<A> &a){
  int i;
  if(this==&a) return *this;
  delete []mem;
  vol=a.vol;
  max_vol=a.max_vol;
  mem=new int[max_vol];
  for(i=0; i<vol; i++) mem[i]=a.mem[i];
  return *this;
}

template <class A>
int &Array<A>::operator[](int index){
  if((0<=index)&&(index<vol)) return mem[index];
  exit(1);
}

template <class A>
void Array<A>::add(A element){
  int i;
  if(vol!=max_vol){
   i=vol;
   ++vol;
   mem[i]=element;
  }
  else{
   max_vol+=10;
   A *t=new A[max_vol];
   for(i=0; i<vol; i++) t[i]=mem[i];
   delete []mem;
   mem=t;
   ++vol;
   mem[vol-1]=element;
  }
}

template <class A>
void Array<A>::insert(int index, A element){    ///
  int i;
  if(vol!=max_vol){
   ++vol;
  for(i=vol-1; i>index; i--) mem[i]=mem[i-1];
  mem[i]=element;
  }
  else{
   max_vol+=10;
   A *t=new A[max_vol];
   for(i=0; i<index; i++) t[i]=mem[i];
   t[i]=element;
   ++vol;
   for(++i;i<vol; i++) t[i]=mem[i-1];
   delete []mem;
   mem=t;
  }
}

template <class A>
void Array<A>::remove(int index){       ///index=0
  int i=index;
  if((i<0)||(i>vol)){
   puts("error index is out of range"); exit(1);
  }
  while(i!=vol){
   mem[i]=mem[i+1];
   i++;
  }
  --vol;
}

template <class A>
void Array<A>::resize(int n){         ////vol
  if(n<=max_vol) vol=n;
  if(n>max_vol){
   max_vol=n+10;
   A *t=new A[max_vol];
   for(int i=0; i<vol; i++) t[i]=mem[i];
   vol=n;
   delete []mem;
   mem=t;
  }
}

template <class A>
int Array<A>::size()const{
  return vol;
}
