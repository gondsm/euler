/*programa feito assim à pressa para ver se um numero é primo*/
#include <iostream>
using namespace std;

int main(){
	bool primo = true;
	int n;
	cin >> n;
	for(int i = 2; i < n/2; i++)
		if(n % i == 0) primo = false;


	cout << primo << endl;
	return 0;
}
