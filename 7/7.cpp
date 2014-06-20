//Problema: encontrar o primo numero 10001
#include <iostream>
using namespace std;

bool verifica(int n){
	if(n == 2) return true;
	if(n == 0 || n == 1) return false;
	for(int i = 2; i < n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	int count = 0;
	for(int i = 0; 1; i++){
		if(verifica(i)) count++;
		if(count == 10001){
			cout << "Primo 10001: " << i << '\n'; 
			break;
		}
	}
	return 0;
}
