#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

//The indicies are not being assigned correctly. 
//I believe the problem to begin on line 56.
//8/28/2019

int modPow(int base, int exp, int mod) {
	const int temp = base;
	int a = base;
	for (int i = 1; i < exp; i++) {
		a = (temp * a) % mod;
	}
	return a;
}

int GCD(int a, int b) {
	int gcd;
	for (int i = 1; i <= a && i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}

int ePhi(int a) {
	int counter = 0;
	for (int i = a - 1; i >= 1; i--) {
		if (a % 2 == 0 && i % 2 == 0) {
			i--;
		}
		if (GCD(a, i) == 1) {
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



int main() {

	char answer = 'y';
	int mod;
	int PR[10000];
	while (answer == 'y') {
		int counter = 0;
		cout << "Enter your modulus: " << endl;
		cin >> mod;
		cout << endl;
		cout << endl;
		cout << "Primitive Roots Modulo " << mod << ":" << endl;
		for (int i = 1; i < mod; i++) {
			if (isPrimRoot(i, mod)) {
				PR[counter] = i;
				cout << i << endl;
				counter++;
			}
		}
		cout << endl;
		cout << endl;
		for (int j = 0; j < counter; j++) {
			printChart(PR[j], mod);
		}
		cout << "Would you like another chart?" << endl;

		cin >> answer;
	}

	return 0;
}
