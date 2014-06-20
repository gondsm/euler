//resolvido!
#include <iostream>
#define square(x) (x)*(x)
using namespace std;

int main(){
	int a = 0, b = 0, c = 0;
	for(a = 1; a < 1001; a++)
		for(b = a+1; b < ((1000-a)/2)+1; b++){
			c = 1000 - a - b;
			if(square(a) + square(b) == square(c)){
				cout << "Achei!" << endl << "a = ";
				cout << a << "\nb = " << b << "\nc = " << c;
				cout << "\nabc = " << a*b*c << endl;			
			}
		}
	return 0;
}
