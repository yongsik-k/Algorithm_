#include <iostream>
using namespace std;
int Arr[1001][1001] = { 0 };
int dat[10][10] = { 0 };
int N, K;

int ans = 0;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int sung, grade;
		cin >> sung >> grade;
		// 1. dat �� ���� ��� ��, ó�� ���� ��쿡�� ���� �� ������ �ʿ�

		if (dat[sung][grade] == 0) {
			dat[sung][grade] = 1;
			ans++;
			Arr[sung][grade] = 1;
		}// 2. �� ��°����, ���� �� ���� �ʿ� x �ο����� �Ѿ�� �͸� �Ű澴��.
		else {
			Arr[sung][grade]++;
			if (Arr[sung][grade] > K) {
				ans++;
				Arr[sung][grade] = 1;
			}
		}
	}

	cout << ans;

	return 0;
}