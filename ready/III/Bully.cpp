//#include <iostream>
//#include <cstring>
#include "Bully.h"
//#include <>
//#include <>


/*
#include <iostream>
using namespace std;

int main() {
    unsigned int vector=1, vector1;
	vector1=~vector;//&((1<<base_size)-1);
	
	unsigned int x;
	for(int i=0; i<base_size; ++i){
	 x=vector1%2;
	 vector1>>=1;
	 cout << "vector= " << (float)vector << "\n";
	 cout << "vector1= " << (float)vector1 << "\n";
	 cout << "x= " << x << "\n";
	}
	return 0;
}
*/




/*
class Bully{
private:
  static const unsigned int base_size = 8*sizeof(unsigned int);
  unsigned int *Vec;
  unsigned int vec_Length;
  unsigned int bit_Length;
  unsigned int last_base_size;
public:
  Bully(int n=8*sizeof(unsigned int)){
    this->bit_Length=n;
    this->vec_Length=n/base_size+((n%base_size)/(n%base_size));
    Vec=new unsigned int [this->vec_Length];
    for(int i=0; i<this->vec_Length; ++i) Vec[i]=0;
  }

  ~Bully(){
  	delete[] Vec;
  }

  Bully(char *s);

  Bully operator ~(){
   Bully temporary_vector(vec_Length);
   for(int i=0; i<vec_Length; ++i)
   	temporary_vector.Vec[i]=~Vec[i];//&((1<<bit_Length)-1);
   return temporary_vector;
  }

  Bully operator <<(int count);
  Bully operator >>(int count);
  void setBit(int element, int position);
  unsigned int getBit(int position);
  void set0(int position);
  void set1(int position);
  int vlength();
  int blength();
  Bully &operator =(const Bully &v);
  Bully &operator |(const Bully &v);
  Bully &operator &(const Bully &v);
  Bully &operator ^(const Bully &v);
};
*/

Bully::Bully(unsigned int n){
  bit_Length=n;
  vec_Length=(bit_Length+base_size-1)/base_size;
  last_base_size=base_size-(vec_Length*base_size-bit_Length);
  Vec=new unsigned int [this->vec_Length];
  for(unsigned int i=0; i<this->vec_Length; ++i) Vec[i]=0;
}


Bully Bully::operator ~(){
   Bully temporary_vector(vec_Length);
   for(unsigned int i=0; i<vec_Length; ++i)
   	temporary_vector.Vec[i]=~Vec[i];
   unsigned int mask = UINT_MAX << last_base_size;
   temporary_vector.Vec[vec_Length-1] ^= mask;
   return temporary_vector;
  }


Bully::Bully(char *s){
  bit_Length=strlen(s);
  vec_Length=(bit_Length+base_size-1)/base_size;
  Vec=new unsigned int[vec_Length];
  last_base_size=base_size-(vec_Length*base_size-bit_Length);
  for(unsigned int i=0; i<last_base_size; ++i){
   if(s[i]=='1') Vec[vec_Length-1]|=1;
   Vec[vec_Length-1]<<=1;
  }
  for(int i=(int)vec_Length-2; i>=0; --i)
   for(unsigned int j=0; j<base_size; ++j){
    if(s[j]=='1') Vec[i]|=1;
    Vec[i]<<=1;
  }
}


std::ostream &operator <<(std::ostream &r, Bully &v){
  bool x;
  for(int j=(int)v.bit_Length-1; j>=0; --j){
   x=v.getBit(j);
   r <<x;
  }
  return r;
}



bool Bully::operator ==(const Bully &v){
  if((vec_Length!=v.vec_Length)||(bit_Length!=v.bit_Length))
   return false;
  for(unsigned int i=0; i<vec_Length; ++i)
   if(Vec[i]!=v.Vec[i]) return false;
  return true;
}



//Исправить
Bully &Bully::operator =(const Bully &v){
unsigned int len=v.vlength();
if(len==vec_Length)
 for(unsigned int i=0; i<len; ++i)
  Vec[i]=v.Vec[i];
else{
 delete[] Vec;
 vec_Length=len;
 for(unsigned int i=0; i<len; ++i)
  Vec[i]=v.Vec[i];
}
return *this;
}

Bully Bully::operator |(const Bully &v){
Bully temporary_vector(vec_Length);
for(unsigned int i=0; i<vec_Length; ++i)
 temporary_vector.Vec[i]=Vec[i]|v.Vec[i];
return temporary_vector;
}

Bully Bully::operator &(const Bully &v){
Bully temporary_vector(vec_Length);
for(unsigned int i=0; i<vec_Length; ++i)
 temporary_vector.Vec[i]=Vec[i]&v.Vec[i];
return temporary_vector;
}

Bully Bully::operator ^(const Bully &v){
  Bully temporary_vector(vec_Length);
  for(unsigned int i=0; i<vec_Length; ++i)
   temporary_vector.Vec[i]=Vec[i]^v.Vec[i];
  return temporary_vector;
}


void Bully::operator >>(unsigned int count){
  if(count>=bit_Length)//нулевой вектор
   for(unsigned int i=0; i<vec_Length; ++i) Vec[i]=0;
  else{
   int x=count/base_size;
   if(x){//массив вектора сдвигается на целое
    int j=0;
    while(j!=x){
     for(unsigned int i=0; i+1<vec_Length; ++i)
      Vec[i]=Vec[i+1];
      Vec[vec_Length]=0;
     ++j;
    }
   }
   x=count%base_size;
   if(x){//Массив вектора сдвигается на остатки
    int i;
    for(i=vec_Length-1; Vec[i]==0; --i);
    int temp=Vec[i];
    Vec[i]<<=x;
    while(i-1>=0){
     int mask=1;
     mask<<=base_size-last_base_size;
     mask&=temp;
     mask>>=base_size-x;
     temp=Vec[--i];
     Vec[i]<<=x;
     Vec[i]|=mask;
    }
   }
  }
}




void Bully::operator <<(unsigned int count){
  if(count>=bit_Length){//нулевой вектор
   for(unsigned int i=0; i<vec_Length; ++i) Vec[i]=0;
   return;
  }
  int x=count/base_size;
  if(x){//массив вектора сдвигается на целое
   int j=0;
   while(j!=x){
     for(unsigned int i=0; i+1<vec_Length; ++i)
      Vec[i]=Vec[i+1];
      Vec[vec_Length]=0;
     ++j;
    }
   }
   x=count%base_size;
   if(x){//Массив вектора сдвигается на остатки
    int i;
    for(i=vec_Length-1; Vec[i]==0; --i);
    int temp=Vec[i];
    Vec[i]<<=x;
    while(i-1>=0){
     int mask=1;
     mask>>=base_size-last_base_size;
     mask&=temp;
     mask<<=base_size-x;
     temp=Vec[--i];
     Vec[i]<<=x;
     Vec[i]|=mask;
    }
   }
}


int Bully::vlength()const{
return vec_Length;
}

int Bully::blength()const{
return bit_Length;
}

void Bully::setBit(unsigned int element, unsigned int position){
if((position>=bit_Length)||(position<0))
 throw indexException(bit_Length, position);
unsigned int target_base=vec_Length-(position/base_size);
unsigned int vector=1;
vector<<=position%base_size;
Vec[target_base]=Vec[target_base]&~vector;
if(element){
 vector=~vector;
 Vec[target_base]=Vec[target_base]|vector;
}
}



bool Bully::getBit(unsigned int position)const{
	if((position>=bit_Length)||(position<0))
	 throw indexException(bit_Length, position);
	unsigned int target_base =(position/base_size);
	unsigned int mask = 1;
	mask<<=position%base_size;
	return !!(Vec[target_base]&mask);
}



void Bully::set0(unsigned int position){
if((position>=bit_Length)||(position<0))
 throw indexException(bit_Length, position);
unsigned int target_base = vec_Length-(position/base_size);
unsigned int mask = 1;
mask<<=position%base_size;
Vec[target_base]=Vec[target_base]&~mask;
}



void Bully::set1(unsigned int position){
if((position>=bit_Length)||(position<0))
 throw indexException(bit_Length, position);
unsigned int target_base=vec_Length-(position/base_size);
unsigned int vector=1;
vector<<=position%base_size;
Vec[target_base]=Vec[target_base]|vector;
}

