#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Arr[7][7] = {
	{0,0,0,0,0,0,0},
	{0,0,1,0,1,0,0},
	{0,1,2,0,2,1,0},
	{0,0,1,2,1,0,0},
	{0,0,2,1,0,1,0},
	{0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0}
};
int Y, X;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cnt = 0;
int ans;
int isReal(int y, int x) {
	ans = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= 7 || ny >= 7)continue;
		if (Arr[ny][nx] == 1) {
			ans++;
		}
	}
	if (ans == 4) {
		return 1;
	}

	return 0;
}


int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);
	cin >> Y >> X;
	Arr[Y][X] = 1;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (Arr[i][j] == 2) {
				cnt += isReal(i, j);
			}
		}
	}
	cout << cnt;


	return 0;
}