#include <iostream>
using namespace std;

bool verify_prime(int n){
	if(n == 2) return true;
	if(n == 0 || n == 1) return false;
	for(int i = 2; i < n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	unsigned long long int supanumba = 600851475143;
	//int supanumba = 6;
	/*Build a table of prime numbers*/
	int primes[1000];
	int spot = 0;
	for(int i = 0; spot < 1000; i++)
		if(verify_prime(i)){
		primes[spot] = i;
		spot++;
		} 
	spot = 0;
	/**/

	for(int i = 0; supanumba != 1; i++){
		if(supanumba % primes[spot] == 0){
			supanumba = supanumba / primes[spot];
		}
		else spot++;
	} 	
	cout << "The largest prime factor of 600851475143 e " << primes[spot] << endl;
	return 0;
}
