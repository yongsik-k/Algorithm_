//Top Down
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Arr[10001];
int dp[10001];
int Val, n;
int main() {
	int Val, n;
	cin >> Val >> n;
	for (int i = 1; i <= n; i++) {
		cin >> Arr[i];
	}
	for (int i = 1; i <= Val; i++) {
		dp[i] = 99999;
	}
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = Arr[i]; j <= Val; j++) {
			dp[j] = min(dp[j], dp[j - Arr[i]] + 1);
		}
	}
	if (dp[Val] == 99999) {
		cout << "impossible" << endl;
	}
	else cout << dp[Val] << endl;


	return 0;
}