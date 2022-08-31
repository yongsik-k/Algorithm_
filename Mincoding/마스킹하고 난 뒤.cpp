#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Map[3][3] = {
	{3,5,1},
	{3,8,1},
	{1,1,5}
};

int bitarray[2][2];
int sum;
int Max = -2134567890;
int maxX = 0, maxY = 0;

void isFind(int y, int x) {
	sum = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (bitarray[i][j] == 1) {
				int ny = y + i;
				int nx = x + j;
				if (ny < 0 || nx < 0 || nx >= 3 || ny >= 3)continue;
				sum += Map[ny][nx];
				if (sum > Max) {
					Max = sum;
					maxX = x;
					maxY = y;
				}
			}
		}
	}

}


int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> bitarray[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			isFind(i, j);
		}
	}

	cout << "(" << maxY << "," << maxX << ")";
	return 0;
}