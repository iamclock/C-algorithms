#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>


template <class stacktype>
class Stack{
private:
 int size, last;
 stacktype *stack;
public:
  Stack(int count=15);
  ~Stack();
  bool check();
  void push(stacktype element);
  stacktype get();
};

template <class stacktype>
Stack<stacktype>::Stack(int count){
  size=count;
  stack=new stacktype[size];
  last=0;
}

template <class stacktype>
Stack<stacktype>::~Stack(){delete[]stack;}

template <class stacktype>
bool Stack<stacktype>::check(){
  if(last==size) std::cout <<"Stack is full" <<"\n";
  else std::cout <<"Alright, maaan" <<"\n";
  return last==size;
}

template <class stacktype>
void Stack<stacktype>::push(stacktype element){
  if(last==size){
   std::cout << "Stack is full\n";
  }
  stack[last]=element;
  ++last;
}

template <class stacktype>
stacktype Stack<stacktype>::get(){
  stacktype ch;
  if(last==0) std::cout << "Stack is empty\n";
  else{
   std::cout <<stack[last];
   ch=stack[last];
   --last;
  }
  return ch;
}
