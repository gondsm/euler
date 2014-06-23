#include <iostream>

// Multiplying two 3-digit numbers always results in a 5 or 6 digit number, because:
// 100x100 = 10000, 999x999 = 998001. Thus, we need to account for numbers with odd
// or even number of digits.
bool verify_if_palindrome(int n){
	// Determine how long the number is
	int aux1 = n;
	int i = 0;
	for( ; aux1 != 0; i++)
		aux1 = aux1 / 10;
	// Number has i digits
	if(i % 2 == 0){ // If number of digits is even
		int aux2[6];
		for(int i = 0; i < 6; i++){
			aux2[i] = n % 10;
			n = n / 10;
		}
		if(aux2[0] == aux2[5] && aux2[1] == aux2[4] && aux2[2] == aux2[3]) return true; // Actual verification
		else return false;
		
	} else{		// Number of digits is odd
		int aux2[5];
		for(int i = 0; i < 5; i++){
			aux2[i] = n % 10;
			n = n / 10;
		}
		if(aux2[0] == aux2[4] && aux2[1] == aux2[3]) return true; // Actual verification
		else return false;
	}
}

int main(){
	// Brute force:
	int largest_palindrome = 0, ra = 0, rb = 0;
	for(int i = 100; i < 1000; i++)
		for(int j = 100; j < 1000; j++)
			if(verify_if_palindrome(i*j) && i*j > largest_palindrome){largest_palindrome = i*j; ra = i; rb = j;}

	
	std::cout << "Result: " << largest_palindrome << std::endl;
	std::cout << "Which is the product of " << ra << " by " << rb << std::endl;
	
	return 0;
}
