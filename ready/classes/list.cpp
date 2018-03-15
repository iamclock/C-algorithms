#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>



class Spisok{
private:
int nodes;
struct node{
int obj;
node *next;
};
node *begin;
node *end;
public:
  Spisok();
  Spisok(int val);
  ~Spisok();
  void insert(int iterator, int val);
  void push_back(int val);
  void push_front(int val);
  void erase(int iterator);
  int pop_front();
  int pop_back();
  int getsize();
  void reverse();
  void print();
};

Spisok::Spisok(){
  nodes=0;
  end=begin=NULL;
}

Spisok::Spisok(int val){
  nodes=1;
  node *cur=new node;
  cur->obj=val;
  cur->next=NULL;
  begin=cur;
  end=cur;
}

Spisok::~Spisok(){
  node *cur;
  cur=begin;
  node *todel;
  while(cur){
   todel=cur;
   cur=cur->next;
   delete todel;
  }
}
void Spisok::insert(int iterator, int val){     ///проверка на
  if(iterator>nodes){                           ///NULL
   puts("Iterator is larger than can be.");     ///index=0
   exit(1);
  }
  int i=0;
  node *cur;
  cur=begin;
  node *temp=new node;
  temp->obj=val;
  if(iterator==0){
   temp->next=begin;
   if(nodes==0) end=begin;
   else begin=temp;
  }
  else if(iterator==nodes){
   end->next=temp;
   end=temp;
  }
  else{
   while(iterator-1!=i){
    i++;
    cur=cur->next;
   }
   temp->next=cur->next;
   cur->next=temp;
  }
  nodes++;
}
void Spisok::push_back(int val){      //NULL
  node *cur=new node;
  cur->obj=val;
  cur->next=NULL;
  if(nodes==0) begin=end=cur;
  else{
   end->next=cur;
   end=cur;
  }
  nodes++;
}
void Spisok::push_front(int val){      //NULL
  node *cur=new node;
  cur->obj=val;
  cur->next=begin;
  begin=cur;
  if(nodes==0) end=cur;
  nodes++;
}

void Spisok::erase(int iterator){
  if(iterator>nodes-1){
   puts("iterator is larger than number of nodes.");
   exit(1);
  }
  int i=0;
  node *cur, *tmp;
  cur=begin;
  while(i<iterator){
   tmp=cur;
   cur=cur->next;
   i++;
  }
  if(i==0){
   if(begin!=end) begin=begin->next;
   else{
    begin=end=NULL;
    std::cout <<"List is Empty" <<"\n";
   }
   delete cur;
  }
  else if(i==nodes-1){                  //nodes-1
   end=cur;
   delete cur->next;
   end->next=NULL;
  }
  else{
   tmp->next=cur->next;
   delete cur;
  }
  nodes--;
}

int Spisok::pop_front(){
  int tmp;
  node *cur;
  if(nodes==0){
   puts("ERROR. List is empty");
   exit(1);                         //return;
  }
  cur=begin;
  std::cout<<cur->obj<<"\n";
  tmp=cur->obj;
  if(begin!=end) begin=cur->next;
  else{
   begin=end=NULL;
   std::cout <<"It was last element. Now list is Empty." <<"\n";
  }
  nodes--;
  delete cur;
  return tmp;
}

int Spisok::pop_back(){
  node *cur;
  int tmp;
  if(nodes==0){
   puts("ERROR. List is empty");
   exit(1);                         //return;
  }
  cur=begin;
  if(nodes==1){
   std::cout <<cur->obj <<"\n";
   tmp=cur->obj;
   delete cur;
   begin=end=NULL;
   std::cout <<"It was last element. Now list is Empty." <<"\n";
   return tmp;
  }
  while(cur->next->next){
   cur=cur->next;
  }
  std::cout<<cur->next->obj<<"\n";
  tmp=cur->next->obj;
  end=cur;
  delete cur->next;
  end->next=NULL;
  nodes--;
  return tmp;
}

int Spisok::getsize(){
  return nodes;
}

void Spisok::reverse(){
  if(nodes!=0&&nodes!=1){
   node *one;
   node *two;
   node *three;
   one=begin;
   begin=end;
   end=one;
   two=one->next;
   end->next=NULL;
   three=two->next;
   while(two){
    two->next=one;
    one=two;
    two=three;
    if(three) three=three->next;
   }
  }
}

void Spisok::print(){
  node *cur;
  cur=begin;
  while(cur){
   std::cout<<cur->obj<<" ";
   cur=cur->next;
  }
  std::cout<<"\n";
}
