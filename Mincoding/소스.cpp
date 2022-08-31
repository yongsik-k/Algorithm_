#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> Arr;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0};
int Col, bombNum;
int dat[1000][10] = {0};
int used[1000][10] = { 0 };
int flag = 0;
int dat2[100];

void zeroSort2(int y, int x) {
	int col = y, row = x;
	for (int i = col-1; i >= 0; i--) {
		if (Arr[i][row] != '0') {
			char temp = Arr[i][row];
			Arr[i][row] = Arr[col][row];
			Arr[col][row] = temp;
			return;
		}
	}
	flag = 1;
	return;
}

void zeroSort(int x) {
	int row = x;
	for (int i = Col-1; i >= 0; i--) {
		if (Arr[i][row] == '0') {
			zeroSort2(i, row);
		}
	}
	return;
}

// 여기서 부터는 이제 실제로 없애는 범위 dat 관련된것을 다 포함시켜야 해.
//used[ny][nx] = 0;
void realBomb(int y, int x) {
	dat[y][x] = 1;
	char A = Arr[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= Col || nx >= 10)continue;
		if (Arr[ny][nx] == A) {
			dat[ny][nx] = 1;
			if (used[ny][nx] == 1)continue;
			used[ny][nx] = 1;
			realBomb(ny, nx);
		}
	}
	return;
}


// 1. 인덱스 받고 폭탄 찾기
void findBomb(int y, int x) {
	char A = Arr[y][x];
	if (Arr[y][x] == '0') return;
	int cnt = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= Col || nx >= 10)continue;
		if (Arr[ny][nx] == A) {
			cnt++;
		}
	}
	if (cnt >= 3) {
		realBomb(y, x);
	}
	return;
}

int main() {

	cin >> Col >> bombNum;
	
	// 0. 입력 받기

	for (int i = 0; i < Col; i++) {
		string temp;
		cin >> temp;
		Arr.push_back(temp);
	} // 수정할 것 없어.

	int bbbb = 0;
	while (bbbb<150) {
	

		// 1. 한 인덱스씩 넘기기
		for (int i = 0; i < Col; i++) {
			for (int j = 0; j < 10; j++) {
				findBomb(i, j);
			}
		} // 수정 x
		//폭탄을 다 찾았으니 Bomb 시키자. bomb 시키고 dat는 다시 0으로 만드는 것.
		for (int i = 0; i < Col; i++) {
			for (int j = 0; j < 10; j++) {
				if (dat[i][j] == 1) {
					Arr[i][j] = '0';
					dat[i][j] = 0;
					used[i][j] = 0;
				}
			}
		}
		flag = 0;
		//0으로 정렬하기
		for (int i = 0; i < 10; i++) {
			zeroSort(i);
		}
		bbbb++;
		if (flag == 0) {
			break;
		}
		flag = 0;


	}
	/////////////////////////////////////
	// 마지막 출력

	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < 10; j++) {
			cout<<Arr[i][j];
		}cout << '\n';
	}

	return 0;
}