#ifndef SORTER_H
#define SORTER_H


#include "Array.h"
#include <cstdio>
#include <assert.h>





template <class ArrayType>
void swap(ArrayType *a, ArrayType *b);


template <class ArrayType>
class Sorter{
public:
  enum SortType{
    shell=0,
    quick=1,
    bubble=2,
    selection=3,
    insertion=4,
    heap=5
  };
  Sorter(SortType enum_sort=shell);
  void sort(Array<ArrayType> &a);
	//sort с копированием массива
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


#endif
