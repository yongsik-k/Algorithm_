#include <iostream>
using namespace std;
int Arr[150][150] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int ans=0;
	// �׳� �Է¹��� ���� ���θ� 1�� ����� 1�� ������ ���� �ȴ�.
	for (int i = 0; i < 4; i++) {
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		for (int i = Y1; i < Y2; i++) {
			for (int j = X1; j < X2; j++) {
				Arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 150; i++) {
		for (int j = 0; j < 150; j++) {
			ans += Arr[i][j];
		}
	}
	cout << ans;
	return 0;
}