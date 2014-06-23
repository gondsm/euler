#include <iostream>


int main(){
	// Sum of the squares:
	int sum1 = 0;
	for(int i = 1; i <= 100; i++)
		sum1 = sum1 + (i*i);
	// Square of the sum:
	int sum2 = 0;
	for(int i = 1; i <=100; i++)
		sum2 = sum2 + i;
	sum2 = sum2 * sum2;
	// Result
	int result = sum2 - sum1;
	std::cout << "The difference is " << result << "\n";
	return 0;
}
