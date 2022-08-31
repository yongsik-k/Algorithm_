#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int Arr[101][101] = { 0 };


int sumx() {
	int max = -21e8;
	int sum = 0;
	int a = 0;
	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += Arr[i][j];
		}
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}

int sumy() {
	int max = -21e8;
	int sum = 0;
	int a = 0;

	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += Arr[j][i];
		}
		if (sum > max) {
			max = sum;
		}
	}


	return max;
}

int sumda() {
	int a = 0;
	int b = 0;
	int sum = 0;
	int a2 = 0;
	int b2 = 99;
	int sum2 = 0;

	while (a < 100) {
		sum += Arr[a][b];
		a++;
		b++;
	}
	while (a2 < 100) {
		sum2 += Arr[a2][b2];
		a2++;
		b2--;
	}

	if (sum > sum2) {
		return sum;
	}
	else {
		return sum2;
	}


}

int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);
	
	for (int tc = 0; tc < 10; tc++) {
		int tcnum;
		cin >> tcnum;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> Arr[i][j];
			}
		}
		int x = sumx();
		int y = sumy();
		int da = sumda();

		int result1 = max(x, y);
		int realresult = max(result1, da);

		cout << "#" << tcnum << " " << realresult << '\n';
	}



	return 0;
}