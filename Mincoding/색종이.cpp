#include <iostream>
using namespace std;
int Arr[1002][1002] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	// ���δ� �ߺ��� ����� ä, �Է� �ޱ�
	for (int tc = 1; tc <= test_case; tc++) {
		int X, Y, rangeX, rangeY;
		cin >> X >> Y >> rangeX >> rangeY;
		for (int i = Y; i < Y + rangeY; i++){
			for (int j = X; j < X + rangeX; j++) {
				Arr[i][j] = tc;
			}
		}
	}
	// Tc ���� ��ŭ ��¸� ���ָ� �ȴ�.
	int cnt;
	for (int tc = 1; tc <= test_case; tc++) {
		cnt = 0;
		for (int i = 0; i < 1002; i++) {
			for (int j = 0; j < 1002; j++) {
				if (Arr[i][j] == tc) {
					cnt++;
				}
			}
		}
		cout << cnt<<'\n';
	}


	return 0;
}