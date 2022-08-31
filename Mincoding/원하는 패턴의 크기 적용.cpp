#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Arr[4][5] = {
	{3,5,4,2,5},
	{3,3,3,2,1},
	{3,2,6,7,8},
	{9,1,1,3,2}
};


int a, b;
int sum;
int Max = -2134567890;
int index_x;
int index_y;
void pattern(int y, int x) {

	sum = 0;

	for (int i = y; i < y + a; i++) {
		for (int j = x; j < x + b; j++) {
			if (i < 0 || j < 0 || i >= 4 || j >= 5)continue;
			sum += Arr[i][j];
			if (sum > Max) {
				Max = sum;
				index_y = y;
				index_x = x;
			}
		}
	}

	return;
}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);

	cin >> a >> b;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			pattern(i, j);
		}
	}

	cout << "(" << index_y << "," << index_x << ") ";

	return 0;
}