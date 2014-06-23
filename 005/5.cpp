#include <iostream>

bool isDivisible(int n){
	for(int i = 20; i > 2; i--)
		if(n % i != 0) return false;

	return true;
}

int main(){
	int result = 0;
	for(unsigned long long int i = 20; 1; i = i + 20){
		if(isDivisible(i)){
			result = i;
			break;
		}
	}
	std::cout << "The smallest number divisible by every integer between 1 and 20 is " << result << std::endl;

	return 0;
}
