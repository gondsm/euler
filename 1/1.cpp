#include <iostream>
using namespace std;

int main(){
	cout << "\n..::Calculando soma de multiplos de 3 e 5 abaixo de 1000::..";
	int soma = 0;
	for(int i = 0; i < 1000; i++)
		if(i % 3 == 0 || i % 5 == 0) soma = soma + i;

	cout << endl << soma << endl;
	return 0;
}
