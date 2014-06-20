//Precisa de um algoritmo novo. O programa resolve teoricamente o problema,
//mas demoraria várias horas.
//Tenho dúvidas quanto à capacidade de um unsigned long long para guardar um
//número tão grande.

//v2.0: Utilização do teorema de Wilson para determinação dos números primos reduz
//radicalmente o número de divisões (de n/2 para 1). Problema: factoriais de
//números astronómicos.

//v3: reescrita completa, utilizando o Crivo de Erastótenes.

//Resolvido.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
	//Criação da tabela:
	unsigned int tab [2000000];
	for(int i = 0; i < 2000000; i++)
		tab[i] = i;
	//Eliminação:
	int j = 2;
	int p = 0;
	while(p*p < 2000000){
		p = tab[j];
		if(p*p > 2000000) break;
		tab[p*p] = 0;
		int q = p*p;
		while(q < 2000000){
			// cout << setw(7) << q << ' ' << p << endl;
			tab[q] = 0;
			q = q + p;
		}
		j = p + 1;
		while(tab[j] == 0 && j < 1423){
			j++;
		}
	}
	//Soma:
	
	unsigned long long int soma = 0;
	for(int i = 2; i < 2000000; i++){
		soma += tab[i];
	}
	cout << "Soma = " << soma << endl;
	
	//Debug:
	/*ofstream dados;
	dados.open("tab.txt");
	for(int i = 0; 1 < 2000000; i++){
		if(tab[i] != 0) dados << tab[i] << ", ";
	}
	dados.close();*/
			
	return 0;
}
