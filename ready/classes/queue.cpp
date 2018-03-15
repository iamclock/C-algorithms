#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>


template <class Q>
class Queue{
public:
  Queue(int max_n=15);
  ~Queue();
  void add(Q x);
  Q get();
  bool check();
private:
int i, j, n;
Q *p;};
//:::::::::::::::::::::::::

template <class Q>
Queue<Q>::Queue(int max_n){
  p=new int[max_n];
  n=max_n;
  i=j=0;
}

template <class Q>
Queue<Q>::~Queue() {delete[]p;}

template <class Q>
void Queue<Q>::add(Q x){
  if(j<n){
   p[j]=x;
   j++;
  }
  else if(j==n&&i==n){
   i=j=0;
   this->add(x);
  } else std:: cout << "Queue line is Full\n";
}

template <class Q>
Q Queue<Q>::get(){
  Q ch;
  ch=p[i];
  std::cout << p[i] << " ";
  i++;
  return ch;
}

template <class Q>
bool Queue<Q>::check(){
  if(n==j) std::cout <<"Queue is full" <<std::endl;
  else std::cout <<"Alright, maaan" <<"\n";
  return n==j;
}
