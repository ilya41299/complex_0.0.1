#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct complex_t {
   float real;
   float imag;
  }
  ch,ch1;
bool test(istringstream & stream, complex_t & ch)
{
  char sim1,sim2,sim3;
  bool p=1;
  if ( ((stream>>sim1) && (sim1== '(')) && ((stream>>ch.real) && (stream>>sim2)) && ((sim2==',') && ((stream>>ch.imag) && (stream>>sim3)) && (sim3 == ')' ))){
    p=1;}
  else p=0;
  return p;
}

complex_t add(complex_t ch1, complex_t ch2){
  complex_t ch;
  ch.real=ch1.real+ch2.real;
  ch.imag=ch1.imag+ch2.imag;
  return ch;
}

complex_t sub(complex_t ch1, complex_t ch2){
  complex_t ch;
  ch.real=ch1.real-ch2.real;
  ch.imag=ch1.imag-ch2.imag;
  return ch;
}

complex_t mul(complex_t ch1, complex_t ch2){
  complex_t ch;
  ch.real=ch1.real*ch2.real-ch1.imag*ch2.imag;
  ch.imag=ch1.imag*ch2.real+ch1.real*ch2.imag;
  return ch;
}

complex_t div(complex_t ch1, complex_t ch2){
  complex_t ch;
  ch.real=(ch1.real*ch2.real+ch1.imag*ch2.imag)/(ch2.real*ch2.real+ch2.imag*ch2.imag);
  ch.imag=(ch1.imag*ch2.real-ch1.real*ch2.imag)/(ch2.real*ch2.real+ch2.imag*ch2.imag);
  return ch;
}
void write(complex_t ch){
  cout<<endl<<"("<<ch.real<<","<<ch.imag<<")"<<endl;
}

int main ()
{
  string stroka;
  getline (cin,stroka);
  istringstream stream (stroka);
  complex_t ch1;
  complex_t ch2;
  char op;

   if(test(stream,ch1)) {
     stream >> op;
     if ((op!='+') && (op!='-') && (op!='*') && (op!='/')){
       cout << "An error has occured while reading input data"<<endl;
       return -1;
       }
}
  else {cout<<"An error has occured while reading input data"<<endl;
 return -1;}
  if (test(stream,ch2)) {
  switch (op) {
    case '+': {ch = add(ch1,ch2);
          break;};
    case '-': {ch = sub(ch1,ch2);
          break;};
    case '*': {ch = mul(ch1,ch2); 
          break;};
    case '/': {ch = div(ch1,ch2); 
          break;};
    default : {cout << " An error has occured while reading input data "; 
          break;}
    }
    write(ch);
  }
  return 0;
}
