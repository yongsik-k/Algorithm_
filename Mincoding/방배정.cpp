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
		// 1. dat 가 없을 경우 즉, 처음 들어가는 경우에는 최초 방 생성이 필요

		if (dat[sung][grade] == 0) {
			dat[sung][grade] = 1;
			ans++;
			Arr[sung][grade] = 1;
		}// 2. 두 번째부턴, 최초 방 생성 필요 x 인원수가 넘어가는 것만 신경쓴다.
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