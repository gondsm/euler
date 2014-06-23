#include <iostream>
#include <fstream>
using namespace std;

int main(){
	// Number is stored in an ASCII file:
	int supanumba[1000];
	ifstream numba;
	numba.open("supanumba.txt");
	for(int i = 0; i < 1000; i++)
		supanumba[i] = (numba.get() - 48);

	// Find largest product of 5 consecutive digits:
	int mult = 0;
	for(int i = 0; i < 1000; i++){
		int aux = supanumba[i];
		for(int j = 1; j < 5; j++){
			aux = aux * supanumba[i+j];
		}
		if(aux > mult) mult = aux;
	}

	std::cout << "The largest prodct of 5 consecutive digits is: " << mult << std::endl;
	return 0;
}
