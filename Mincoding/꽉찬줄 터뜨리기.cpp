#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Arr[5][4];

void doClear(int y) {

	for (int i = y; i > 0; i--) {
		for (int j = 0; j < 4; j++) {
			int temp = Arr[i - 1][j];
			Arr[i - 1][j] = Arr[i][j];
			Arr[i][j] = temp;
		}
	}

	return;
}

void pop(int y) {
	for (int i = 0; i < 4; i++) {
		Arr[y][i] = 0;
	}
	doClear(y);
	return;
}

int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> Arr[i][j];
		}
	}
	int cnt;
	int flag;
	while (1) {
		for (int i = 4; i >= 0; i--) {
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (Arr[i][j] == 1) {
					cnt++;
				}
				if (cnt == 4) {
					pop(i);
				}
			}
			if (cnt == 4) {
				break;
			}
		}

		if (cnt != 4) {
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << Arr[i][j] << " ";
		}cout << '\n';
	}

	return 0;
}