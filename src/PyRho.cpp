#include <iostream>
#include <numeric>

using namespace std;

//The indicies are not being assigned correctly. 
//8/28/2019

int modPow(int base, int exp, int mod) {
	const int temp = base;
	int a = base;
	for (int i = 1; i < exp; i++) {
		a = (temp * a) % mod;
	}
	return a;
}

int ePhi(int a) {
	int counter = 0;
	for (int i = a - 1; i >= 1; i--) {
		if (a % 2 == 0 && i % 2 == 0) {
			i--;
		}
		if (gcd(a, i) == 1) {
			counter++;
		}
	}
	return counter;
}


bool isPrimRoot(int a, int mod) {
	int test = ePhi(mod);
	int check = 0;
	for (int j = test; j >= 1; j--) {
		if (modPow(a, j, mod) == 1) {
			check = j;
		}
	}
	if (check == test) { return true; }
	else { return false; }
}

void printChart(int PR, int mod) {
	cout << "Index chart for " << PR << ":" << endl;
	for (int i = 1; i < mod; i++) {
		int a = modPow(PR, i, mod);
		if (a == i) {
			cout << "ind(" << a << ")" << "------>" << i << "***" << endl;
		}
		else {
			cout << "ind(" << a << ")" << "------>" << i << endl;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "invalid usage" << endl;
		return 1;
	}

	int mod = atoi(argv[1]);
	
	cout << "Primitive Roots Modulo " << mod << endl;
	for (int i = 1; i < mod; i++) {
		if (isPrimRoot(i, mod)) {
            printChart(i, mod);
		}
	}

	return 0;
}
