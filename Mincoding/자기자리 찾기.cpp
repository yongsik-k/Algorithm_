#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Arr[8];
int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);

	for (int i = 0; i < 8; i++) {
		cin >> Arr[i];
	}

	int a = 1;
	int b = 7;
	int pivot_a = 0;
	int pivot_b = 0;
	while (a <= b) {
		for (int i = a; i < 8; i++) {
			if (Arr[i] > Arr[0]) {
				pivot_a = i;
				break;
			}
			a++;
		}
		for (int i = b; i >= 0; i--) {
			if (Arr[i] < Arr[0]) {
				pivot_b = i;
				break;
			}
			b--;
		}

		if (a > b) break;

		int temp = Arr[pivot_b];
		Arr[pivot_b] = Arr[pivot_a];
		Arr[pivot_a] = temp;

	}



	int temp = Arr[b];
	Arr[b] = Arr[0];
	Arr[0] = temp;
	for (int i = 0; i < 8; i++) {
		cout << Arr[i] << " ";
	}




	return 0;
}