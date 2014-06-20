/*O programa foi verificado para um numero pequeno (i.e. um int)
 *falta apenas pô-lo a funcionar com um número riduculamente grande,
 *o tal 600851475143.
*/
#include <iostream>
using namespace std;

bool verifica(int n){
	if(n == 2) return true;
	for(int i = 2; i < n; i++){
		if(n % i == 0) return false;
		return true;
	}
	return true;
}

int main(){
	//unsigned long long int supanumba = 600851475143;
	int supanumba = 6;
	/*Preenche uma tabela com numeros primos*/
	int primos[1000];
	int spot = 0;
	for(int i = 0; spot < 1000; i++)
		if(verifica(i)){
		primos[spot] = i;
		spot++;
		} 
	spot = 0; //Por esta altura, primos[] deverá ter 20 números primos.
	/**/

	for(int i = 0; supanumba != 1; i++){
		if(supanumba % primos[spot] == 0){
			supanumba = supanumba / primos[spot];
		}
		else spot++;
	} 	
	cout << primos[spot] << endl;
	return 0;
}
