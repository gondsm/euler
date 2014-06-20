//Problema: qual é o número mais pequeno que é divisível por todos os números de 1 a 20?
//O algoritmo ainda precisa de melhoramentos, pois demorou mais que 1 minuto a resolver o problema. Cerca de 4-5min.
#include <iostream>

bool verificaSeDivisivel(int n){
	for(int i = 20; i > 2; i--)
		if(n % i != 0) return false;

	return true;
}

int main(){
	int result = 0;
	for(unsigned long long int i = 20; 1; i = i + 20){
		if(verificaSeDivisivel(i)){
			result = i;
			break;
		}
		std::cout << i << "\n";
	}
	std::cout << "O menor numero divisivel por todos os numeros de 1 a 20 e " << result << std::endl;

	return 0;
}
