#include <iostream>


using namespace std;

int main() {
	int a, b, gcd = 1, lcm;
	cout << "Type in two integer number: " << endl;
	cin >> a;
	cin >> b;

	for (int i = 1; i <= max(a,b) ; i++) {
		if (a % i ==0 and b % i==0) {
			gcd = i;
		}
	}

	for (int i = 1; i <= min(a,b); i++) {
		if ((a * i) % b == 0) {
			lcm = a * i;
			break;
		}
	}
	

	cout << " Least Common Multiple of " << a << " and " << b << ": " << lcm << endl;
	cout << " Greatest Common Divider of " << a << " and " << b << ": " << gcd << endl;

	return 0;
}


