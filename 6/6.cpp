//Problema: Qual é a diferença entre a soma dos quadrados e o quadrado da soma dos primeiros 100 numeros naturais (1..100)?
//O algoritmo resolveu o problema numa questão de milissegundos.
#include <iostream>


int main(){
	//Soma dos quadrados:
	int sum1 = 0;
	for(int i = 1; i <= 100; i++)
		sum1 = sum1 + (i*i);
	//Quadrado da soma:
	int sum2 = 0;
	for(int i = 1; i <=100; i++)
		sum2 = sum2 + i;
	sum2 = sum2 * sum2;
	//Resultado
	int result = sum2 - sum1;
	std::cout << "A diferenca e " << result << "\n";
	return 0;
}
