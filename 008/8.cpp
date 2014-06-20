//Problema: encontrar o maior produto de 5 digitos seguidos num numero de 1000 digitos
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int supanumba[1000];
	ifstream numba;
	numba.open("supanumba.txt");
	for(int i = 0; i < 1000; i++)
		supanumba[i] = (numba.get() - 48);

	int mult = 0;
	for(int i = 0; i < 1000; i++){
		int aux = supanumba[i];
		for(int j = 1; j < 5; j++){
			aux = aux * supanumba[i+j];
		}
		if(aux > mult) mult = aux;
	}

	std::cout << "O maior produto de 5 digitos e : " << mult << std::endl;
	return 0;
}
