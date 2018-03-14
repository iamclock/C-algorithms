#ifndef BULLY_H
#define BULLY_H

#include <iostream>
#include <cstring>
#include <exception>
#include <string>
#include <sstream>
#include <climits>





class BvException : public std::exception{};



class indexException : public BvException{
 unsigned int vec_bit_len;
 int index;
 std::string msg;
 
public:
 indexException(unsigned int input_vec_bit_len, int input_index):
  vec_bit_len(input_vec_bit_len), index(input_index){};
 
 ~indexException() throw(){}
 
 virtual const char* what() const throw(){
  std::stringstream str_stream;
  str_stream<<"BvException: index out of range. index: " <<index 
  <<", bit length of vector: " <<vec_bit_len;
//  msg <<str_stream;
  return msg.c_str();
 }
};



class Bully{
private:
  static const unsigned int base_size = 8*sizeof(unsigned int);
  unsigned int *Vec;
  unsigned int vec_Length;
  unsigned int bit_Length;
  unsigned int last_base_size;
public:
  Bully(unsigned int n=base_size);
  ~Bully(){
   delete[] Vec;
  }
  Bully(char *s);
  Bully operator ~();
  void operator >>(unsigned int count);
  void operator <<(unsigned int count);
  void setBit(unsigned int element, unsigned int position);
  bool getBit(unsigned int position)const;
  void set0(unsigned int position);
  void set1(unsigned int position);
  int vlength()const;
  int blength()const;
  friend std::ostream &operator <<(std::ostream &r, Bully &v);
  bool operator ==(const Bully &v);
  Bully &operator =(const Bully &v);
  Bully operator |(const Bully &v);
  Bully operator &(const Bully &v);
  Bully operator ^(const Bully &v);
};

#endif
