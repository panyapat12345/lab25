#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag, real*c.imag + c.real*imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	ComplexNumber s;
	s = ComplexNumber(real, imag) * ComplexNumber(c.real, -c.imag);
	return ComplexNumber(s.real/(pow(c.real, 2) + pow(c.imag, 2)), 
						 s.imag/(pow(c.real, 2) + pow(c.imag, 2)));
}

double ComplexNumber::abs(){
	return sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle(){
	double arc = atan2(imag, real);		
	arc = (arc/3.14159265) * 180;			
	return arc;
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag)		return true;
	else										return false;
}

ostream & operator<<(ostream &os, const ComplexNumber &x){
	if(x.real != 0 && x.imag > 0)			return os << x.real << "+" << x.imag << "i" ;
	else if(x.real != 0 && x.imag < 0)		return os << x.real << x.imag << "i" ;
	else if(x.real == 0 && x.imag != 0)		return os << x.imag << "i" ;
	else if(x.real != 0 && x.imag == 0)		return os << x.real ;
	else									return os << "0" ;
}

ComplexNumber operator+(double x, const ComplexNumber &y){
	return ComplexNumber(x+y.real, y.imag);
}

ComplexNumber operator-(double x, const ComplexNumber &y){
	return ComplexNumber(x-y.real, -y.imag);
}

ComplexNumber operator*(double x, const ComplexNumber &y){
	return ComplexNumber(x*y.real, x*y.imag);
}

ComplexNumber operator/(double x, const ComplexNumber &y){
	ComplexNumber s;
	s = x * ComplexNumber(y.real, -y.imag);
	return ComplexNumber(s.real/(pow(y.real, 2) + pow(y.imag, 2)),
						 s.imag/(pow(y.real, 2) + pow(y.imag, 2)));
}

bool operator==(double x, const ComplexNumber &y){
	if(x == y.real && y.imag == 0)		return true;
	else								return false;
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}