#include <iostream>
using namespace std;

int main(){
	cout << "\nCalculating...";
	int sum = 0;
	for(int i = 0; i < 1000; i++)
		if(i % 3 == 0 || i % 5 == 0) sum += i;

	cout << endl << sum << endl;
	return 0;
}
