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

// ���⼭ ���ʹ� ���� ������ ���ִ� ���� dat ���õȰ��� �� ���Խ��Ѿ� ��.
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


// 1. �ε��� �ް� ��ź ã��
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
	
	// 0. �Է� �ޱ�

	for (int i = 0; i < Col; i++) {
		string temp;
		cin >> temp;
		Arr.push_back(temp);
	} // ������ �� ����.

	int bbbb = 0;
	while (bbbb<150) {
	

		// 1. �� �ε����� �ѱ��
		for (int i = 0; i < Col; i++) {
			for (int j = 0; j < 10; j++) {
				findBomb(i, j);
			}
		} // ���� x
		//��ź�� �� ã������ Bomb ��Ű��. bomb ��Ű�� dat�� �ٽ� 0���� ����� ��.
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
		//0���� �����ϱ�
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
	// ������ ���

	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < 10; j++) {
			cout<<Arr[i][j];
		}cout << '\n';
	}

	return 0;
}