#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int z0[4] = { 12,9,3,6 };
int z1[4] = { 9,6,12,3 };
int z2[4] = { 6,3,9,12 };
int z3[4] = { 3,12,6,9 };
int main() {
	int n;
	cin >> n;
	int a = (n / 90) % 4;
	if (a == 0) {
		for (int i = 0; i < 4; i++) {
			cout << z0[i] << " ";
		}
	}
	else if (a == 1) {
		for (int i = 0; i < 4; i++) {
			cout << z1[i] << " ";
		}
	}
	else if (a == 2) {
		for (int i = 0; i < 4; i++) {
			cout << z2[i] << " ";
		}
	}
	else if (a == 3) {
		for (int i = 0; i < 4; i++) {
			cout << z3[i] << " ";
		}
	}

	return 0;
}