#include <iostream>
using namespace std;

int Arr[100][100] = { 0 };
int Dat[100][100] = { 0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int M, N;
int groupCnt=0;
int peoCnt=0;
int Max = -2134567890;

int Find(int y, int x) {


	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= M || nx >= N)continue;
		if (Arr[ny][nx] == Arr[y][x]) {
			if(Dat[ny][nx] == 1) continue;	
			Dat[ny][nx] = 1;

			peoCnt++;
			Find(ny,nx);
		}
	}
	return peoCnt;
}


int main() {
	freopen_s(new FILE *, "input.txt", "r", stdin);

	cin >> M >> N;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
		}
	}

	int Sum;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (Arr[i][j] != 0 && Dat[i][j]==0) {
				Dat[i][j] = 1;
				groupCnt++;
				peoCnt = 1;
				Sum = Find(i, j);
				if (Max < Sum) {
					Max=Sum;
				}
			}
		}
	}
	

	cout << groupCnt << " " << Max;



	return 0;
}