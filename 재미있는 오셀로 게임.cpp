#include <iostream>
using namespace std;
int Arr[10][10] = { 0 };
int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void position(int posi) {
	Arr[posi / 2 - 1][posi / 2 - 1] = 2;
	Arr[posi / 2 - 1][posi / 2] = 1;
	Arr[posi / 2][posi / 2 - 1] = 1;
	Arr[posi / 2][posi / 2] = 2;
	return;
}


int  collect(int ny, int nx, int y, int x, int color) {
	for (int i = 0; i < 4; i++) {
		int nr = ny + dy[i];
		int nc = nx + dx[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N || (nr == y && nc == x))continue;
		if (Arr[nr][nc] == color) {
			if (nr - y == 0 || nc - x == 0) {
				return 1;
			}
		}
	}
	return 0;
}


int oselo(int y, int x, int color) {
	int find = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= N || ny >= N)continue;
		if (color == 1) {
			if (Arr[ny][nx] == 2) {
				find = collect(ny, nx, y, x, color);
				return find;
			}
		}
		if (color == 2) {
			if (Arr[ny][nx] == 1) {
				find = collect(ny, nx, y, x, color);
				return find;
			}
		}

	}

	return find;
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	// tc 입력 여기선 하나니까 잠깐 보류
	int t;
	cin >> t;

	// 1.W,B위치시키기
	cin >> N >> M;
	position(N);

	// 2. 입력
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int abc = oselo(a - 1, b - 1, c);
		int abcdd = 1;
		//제대로 답이 나오면 돌을 추가.

		if (abc == 1) {
			Arr[a - 1][b - 1] = c;
		}
		/*	else if (abc == 0) {
				break;
			}*/

	}




	int sumW = 0, sumB = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Arr[i][j] == 2) {
				sumW++;
			}
			else if (Arr[i][j] == 1) {
				sumB++;
			}
		}
	}

	// 2. 값 리턴받은 것으로 결정한다. 




//

	cout << "#" << t << " " << sumB << " " << sumW;


	return 0;
}