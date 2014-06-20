#include <iostream>
using namespace std;

int fibonacci(long int n){
	if(n == 0) return 1;
	else if (n == 1) return 2;
	else return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(){
	int soma = 0;
	for(int i = 0; fibonacci(i) < 4000000; i++){
		long int x = fibonacci(i);
		if(x % 2 == 0) soma = soma + x;
	}
	cout << "\nO valor da soma de todos os valores pares da sequencia de fibonacci menores que 4 milhoes e: " << soma << endl;
}
