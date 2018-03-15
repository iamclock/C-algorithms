#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>


class Complex{
private:
double re, im;
public:
  Complex(){re=im=0;}
  Complex(double r){
   re=r;
   im=0;
  }
  Complex(double r, double i){
   re=r;
   im=i;
  }
  int operator ==(const Complex &)const;
  Complex& operator +=(const Complex &);
  Complex& operator -=(const Complex &);
  Complex& operator *=(const Complex &);
  Complex& operator /=(const Complex &);
  Complex operator +(const Complex &)const;
  Complex operator -(const Complex &)const;
  Complex operator *(const Complex &)const;
  Complex operator /(const Complex &)const;
  Complex operator -()const;
  double operator !()const{
   return sqrt(re*re+im*im);
  }
  void print(){
   std::cout << "\n" << re << "+i*" << im;
  }
  operator double(){return re;}
  operator char *();
  };
int Complex::operator ==(const Complex &c)const{
  if(re==c.re&&im==c.im) return 1;
  return 0;
}
Complex &Complex::operator +=(const Complex &c){
  re+=c.re;
  im+=c.im;
  return *this;
}
Complex &Complex::operator -=(const Complex &c){
  re-=c.re;
  im-=c.im;
  return *this;
}
Complex &Complex::operator *=(const Complex &c){
  Complex tmp;
  tmp.re=re*c.re-im*c.im;
  tmp.im=im*c.re+re*c.im;
  *this=tmp;
  return *this;
}
Complex &Complex::operator /=(const Complex &c){
  Complex tmp;
  double a;
  a=c.re*c.re+c.im*c.im;
  if(a==0){
   std::cout << "\ndevide 0!";
   exit(1);
  }
  tmp.re=(re*c.re+im*c.im)/a;
  tmp.im=(im*c.re-re*c.im)/a;
  *this=tmp;
  return *this;
}
Complex Complex::operator +(const Complex &c)const{
  Complex tmp;
  tmp.re=re+c.re;
  tmp.im=im+c.im;
  return tmp;
}
Complex Complex::operator *(const Complex &c)const{
  Complex tmp;
  tmp.re=re*c.re-im*c.im;
  tmp.im=im*c.re+re*c.im;
  return tmp;
}
Complex Complex::operator /(const Complex &c)const{
  Complex tmp;
  double a;
  a=c.re*c.re+c.im*c.im;
  if(a==0){
   std::cout << "\n devide 0!";
   getchar();
   exit(1);
  }
  tmp.re=(re*c.re+im*c.im)/a;
  tmp.im=(im*c.re-re*c.im)/a;
  return tmp;
}
Complex Complex::operator -(const Complex &c)const{
  Complex tmp;
  tmp.re=re-c.re;
  tmp.im=im-c.im;
  return tmp;
}
Complex Complex::operator -()const{
  Complex tmp;
  tmp.re=-re;
  tmp.im=-im;
  return tmp;
}
Complex::operator char *(){
  char *s=new char[15], ss[10];
  sprintf(s,"%5.2f", re);
  if(im>0)strcat(s, "+");
  else if(im<0) strcat(s, "-");
  if(!im){
   sprintf(ss, "%5.2f", fabs(im));
   strcat(s, ss);
   strcat(s, "*i");
  }
  return s;
}


int main(){
int i, d;
srand(time(NULL));
std::cout <<"Type 1 for Stack, 2 for Queue, 3 for Array, 4 for List" <<std::endl;
std::cin >>i;
switch(i){
case 1:{
  std::cout <<"Type Stack's size... ";
  std::cin >>d;
  Stack <int> st(d);
  st.check();
  for(i=0; i<d; i++) st.push(i+1);
  st.check();
  std::cout <<"Stack: ";
  for(i=0; i<12; i++){
   st.get();
   std::cout <<" ";
  }
  std::cout <<std::endl;
};break;

case 2:{
  std::cout <<"Type queue's size... ";
  std::cin >>d;
  Queue <int> que(d);
  que.check();
  for(i=0; i<d; i++){
   que.add(i+1);
  }
  que.check();
  for(i=0; i<d; i++) que.get();
  std::cout <<"\n";
};break;

case 3:{
  std::cout <<"Type array's size... ";
  std::cin >>d;
  Array<int> arra(d);
  for(i=0; i<d; i++){
   arra[i]=i+1;
   }
  Array<int> B(d,1);
  for(i=0; i<d; i++) std::cout <<arra[i] <<" ";
  std::cout <<"\n";
  arra.remove(5);
  d=arra.size();
  std::cout <<"remove [5]\n";
  for(i=0; i<d; i++) std::cout <<arra[i] <<" ";
  std::cout <<"\n";
  arra.add(d);
  d=arra.size();
  std::cout <<"add(d)\n";
  for(i=0; i<d; i++) std::cout <<arra[i] <<" ";
  std::cout <<"\n";
  d+=5;
  arra.resize(d);
  std::cout <<"resize(d+5)\n";
  for(i=0; i<d; i++) std::cout <<arra[i] <<" ";
  std::cout <<"\n";
  arra.insert(4, 4);
  d=arra.size();
  std::cout <<"insert 4, 4\n";
  for(i=0; i<d; i++) std::cout <<arra[i] <<" ";
  std::cout <<"\n";
  arra=B;
  d=arra.size();
  std::cout <<d <<std::endl;
  std::cout <<"присвоение знач-ия B\n";
  for(i=0; i<d; i++) std::cout <<arra[i] <<" ";
  std::cout <<std::endl;
};break;
case 4:{
  int ch, d, i;
  Spisok A(12);
  A.push_back(13);
//  std::cout <<ch <<"\n";
  A.push_front(11);
//  std::cout <<ch <<"\n";
  ch=A.getsize();
  std::cout <<"size " <<ch <<"\n";
  std::cout <<"put number of extended list... ";
  std::cin >>d;
  for(i=0; i<d; i++){
   A.push_back(random()%10+1);
  }
  A.print();
  ch=A.getsize();
  std::cout <<"size " <<ch <<"\n";
  A.insert(2, 1);
  A.print();
  A.reverse();
  A.print();
  A.pop_back();
  A.print();
  A.erase(1);
  ch=A.getsize();
  std::cout <<"size " <<ch <<"\n";
  A.print();
  A.pop_front();
  A.print();
};break;
default: break;
}
return 0;
}
