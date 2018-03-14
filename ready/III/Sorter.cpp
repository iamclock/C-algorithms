#include <iostream>
#include "Sorter.h"




/*
template <class ArrayType>
void swap(ArrayType *a, ArrayType *b);


template <class ArrayType>
class Sorter{
public:
  enum SortType{
    shell=0,
    quick=1,
    bubbl=2,
    selec=3,
    inser=4,
    piram=5
  };
  Sorter(SortType enum_sort=shell);
  void sort(Array<ArrayType> &a);
  void change_type(SortType enum_temp);
private:
  SortType Sort;
  void Shell(Array<ArrayType> &a);
  void Quick(Array<ArrayType> &a, int l, int r);
  void Bubble(Array<ArrayType> &a);
  void Selection(Array<ArrayType> &a);
  void Insertion(Array<ArrayType> &a);
  void Piramid(Array<ArrayType> &a);
  void HeapSort(Array<ArrayType> &a);
  void shiftDown(Array<ArrayType> &a, int i, int j);
};
*/


template <class ArrayType>
Sorter<ArrayType>::Sorter(SortType enum_sort){
this->Sort=enum_sort;
}


template <class ArrayType>
void swap(ArrayType *a, ArrayType *b){
 ArrayType t=*a;
 *a=*b;
 *b=t;
}

template <class ArrayType>
void Sorter<ArrayType>::sort(Array<ArrayType> &a){
switch(Sort){
  case shell:
    this->Shell(a);
    break;
  case quick:
    this->Quick(a, 0, a.size()-1);
    break;
  case bubble:
    this->Bubble(a);
    break;
  case selection:
    this->Selection(a);
    break;
  case insertion:
    this->Insertion(a);
    break;
  case heap:
    this->Piramid(a);
    break;
  default: assert(!"Invalid SortType");
}
}

template <class ArrayType>
void Sorter<ArrayType>::change_type(SortType enum_temp){
this->Sort=enum_temp;
}

template <class ArrayType>
void Sorter<ArrayType>::Shell(Array<ArrayType> &a){
int i, j, t, k;
int temp=a.size();
while(temp/=2)
 for(i=0; i<temp; i++)
  for(j=i+temp; j<a.size(); j=j+temp){
   t=a[j];
   for(k=j-temp; (k>=0)&&(t<a[k]); k=k-temp) a[k+temp]=a[k];
   a[k+temp]=t;
  }
}


template <class ArrayType>
void Sorter<ArrayType>::Quick(Array<ArrayType> &a, int l, int r){
int j=r, i=l;
ArrayType p;
p=a[(l+r)>>1];//[n>>1];
while(i<=j){
    while (a[i]<p) i++;
    while (a[j]>p) j--;
    if(i<=j){
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
}
if(j>l) this->Quick(a, l,  j);
if(r>i) this->Quick(a, i, r);
}

template <class ArrayType>
void Sorter<ArrayType>::Bubble(Array<ArrayType> &a){
int i, j;
  for(i=0; i<a.size(); i++)
   for(j=a.size()-1; j>i; j--)
    if (a[j-1]>a[j]) swap(&a[j-1], &a[j]);
}



template <class ArrayType>
void Sorter<ArrayType>::Selection(Array<ArrayType> &a){
int i, j, k;
ArrayType x;
for(i=0; i<a.size(); i++){
  k=i;
  x=a[i];
  for(j=i+1; j<a.size(); j++)
    if (a[j]<x){
      k=j;
      x=a[j];
    }
  a[k]=a[i];
  a[i]=x;
}
}



template <class ArrayType>
void Sorter<ArrayType>::Insertion(Array<ArrayType> &a){
int i, j;
ArrayType x;
for(i=0; i<a.size(); i++){
  x=a[i];
  for(j=i-1; j>=0 && a[j]>x; j--) a[j+1]=a[j];
  a[j+1]=x;
  }
}



template <class ArrayType>
void Sorter<ArrayType>::shiftDown(Array<ArrayType> &a, int i, int j){
int done=0, maxChild, temp;
while((i*2<j) && (!done)){
  if (i*2==j)
    maxChild=i*2;
  else if(a[i*2]>a[i*2+1]) maxChild=i*2;
       else maxChild=i*2+1;
  if(a[i]<a[maxChild]){
    temp=a[i];
    a[i]=a[maxChild];
    a[maxChild]=temp;
    i=maxChild;
  }
  else done=1;
}
}



template <class ArrayType>
void Sorter<ArrayType>::HeapSort(Array<ArrayType> &a){
int i;
ArrayType temp;
for (i=(a.size()/2)-1; i>=0; i--){
  this->shiftDown(a, i, a.size());
}
for (i=a.size()-1; i>=1; i--){
  temp=a[0];
  a[0]=a[i];
  a[i]=temp;
  this->shiftDown(a, 0, i-1);
}
}



template <class ArrayType>
void Sorter<ArrayType>::Piramid(Array<ArrayType> &a){
this->HeapSort(a);
}
