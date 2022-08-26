#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Arr[4][4];

void sumX() {
	int a = 0;
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += Arr[j][i];
		}
		Arr[3][a] = sum;
		a++;
	}
}
//

void sumY() {
	int a = 0;
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += Arr[i][j];
		}
		Arr[a][3] = sum;
		a++;
	}
}

void sumDA() {
	int a = 0;
	int b = 0;
	int sum = 0;
	while (a <= 3) {
		sum += Arr[a][b];
		a++;
		b++;
	}
	Arr[3][3] = sum;

	return;
}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Arr[i][j];
		}
	}

	sumX();
	sumY();
	sumDA();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << Arr[i][j] << " ";
		}cout << '\n';
	}

	return 0;
}