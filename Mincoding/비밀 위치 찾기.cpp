#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
char pattern[2][2] = { 0 };

char Map[3][5] = {
	{"ABGK"},
	{"TTAB"},
	{"ACCD"}
};

int dx[3] = { 1,1,0 };
int dy[3] = { 0 ,1,1 };

int isPattern(int y, int x) {
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= 4 || ny >= 3) continue;
		if (Map[y][x] != pattern[y][x]) continue;
		if (Map[ny][nx] != pattern[ny][nx])continue;
		return 1;
	}
	return 0;
}


int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> pattern[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cnt += isPattern(i, j);
		}
	}
	if (cnt > 0) {
		cout << "발견(" << cnt << "개)";
	}
	else {
		cout << "미발견";
	}

	return 0;
}