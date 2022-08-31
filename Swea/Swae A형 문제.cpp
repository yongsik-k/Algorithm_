#include <iostream>
using namespace std;

int Arr[20][20] = { 0 };
int Dat[20][20] = { 0 };
int saveMax[20][20] = { 0 };

void Find(int y, int x) {
	for (int i = y-Arr[y][x]; i = y+Arr[y][x]; i++) {
		if (Dat[i][x] == 1 || Arr[i][x] == 0)continue;
		Dat[i][x] = 1;
		Find(i, x);
	}

	for (int i = x - Arr[y][x]; i = x + Arr[y][x]; i++) {
		if (Dat[y][i] == 1 || Arr[y][i] == 0)continue;
		Dat[y][i] = 1;
		Find(y, i);
	}
}
int Max = -2134567890;
int Cnt = 0;
int main() {
	freopen_s(new FILE *, "input.txt", "r", stdin);
	
	/*int Tc;
	cin >> Tc;*/
	int N, W, H;
	int stop = 0;
	
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> Arr[i][j];
		}
	}

	while (1) {
		for (int j = 0; j < W; j++) {
			Cnt = 0;
			for (int i = 0; i < H; i++) {
				if (Arr[i][j] >= 1) {
					if (Arr[i][j] == 1) {
						Cnt++;
						Dat[i][j] = 1;
						break;
					}
					Dat[i][j] = 1;
					Find(i, j);
					break;
				}
			}
			if()
		}

		if (stop == N)break;
	}




	return 0;
}