#include <iostream>
using namespace std;
int Arr[10][10] = { 0 };
int path[10] = { 0 };
int used[10] = { 0 };
void dfs(int now) {

	if (now == 7) {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += path[i];
		}
		if (sum == 100) {
			for (int i = 0; i < 7; i++) {
				cout << path[i] << '\n';
			}
			return;
		}
		return;
	}

	for (int next = 0; next < 9; next++) {
		if (Arr[0][next] == 0)continue;
		path[now] = Arr[0][now];
		if (used[next] == 1) continue;
		used[next] = 1;
		dfs(now + 1);

	}

	return;
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		cin >> Arr[0][i];
	}
	dfs(0);


	return 0;
}