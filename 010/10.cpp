//v3: Total rewrite, using the Sieve of Erastotenes.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
	// Table Creation:
	unsigned int tab [2000000];
	for(int i = 0; i < 2000000; i++)
		tab[i] = i;
	// Elimination:
	int j = 2;
	int p = 0;
	while(p*p < 2000000){
		p = tab[j];
		if(p*p > 2000000) break;
		tab[p*p] = 0;
		int q = p*p;
		while(q < 2000000){
			tab[q] = 0;
			q = q + p;
		}
		j = p + 1;
		while(tab[j] == 0 && j < 1423){
			j++;
		}
	}
	// Sum:
	unsigned long long int soma = 0;
	for(int i = 2; i < 2000000; i++){
		soma += tab[i];
	}
	cout << "Sum = " << soma << endl;

	return 0;
}
