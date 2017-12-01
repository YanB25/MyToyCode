#include <cstdio> 
class Complex

{

double real, imag; 

public:

Complex(double x = 0, double y = 0) : real(x), imag(y) { } // constructor, set real = x, imag = y
void print();           //output the complex number with proper form. e.g. 1+i

friend Complex add(const Complex&, const Complex&);   // return sum of two complex numbers 

friend Complex multiply(const Complex&, const Complex&);  // return product of two complex numbers

};

void Complex::print() {
  	if (real == 0 && imag == 0)
      	printf("0\n");
	else if (real == 0) {
    	printf("%gi\n", imag);
  }
  else if (imag == 0) {
    printf("%g\n", real);
  }
  else printf("%g%+gi\n", real, imag);
}

Complex add(const Complex& lhs, const Complex& rhs) {
  Complex ret;
  ret.real = lhs.real + rhs.real;
  ret.imag = lhs.imag + rhs.imag;
  return ret;
}

Complex multiply(const Complex& lhs, const Complex& rhs) {
  Complex ret;
  ret.real = lhs.real * rhs.real - lhs.imag * rhs.imag;
  ret.imag = lhs.real * rhs.imag + lhs.imag * rhs.real;
  return ret;
}


#include<cmath>
#include<iostream>
using namespace std;
int main() {
    double real,imag;
    while (cin >> real >> imag) {
        Complex a = Complex(real,imag);
        cin >> real >> imag;
        Complex b = Complex(real, imag);
        Complex c= add(a,b);
        c.print();
        Complex d = multiply(a,b);
        d.print();
    }
}
