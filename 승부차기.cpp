#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n;
int used[10] = { 0 };
void dfs(int now) {
	if (now == n) {
		cout << now << " " << '\n';
		return;
	}
	for (int next = 1; next <= n; next++) {
		if (used[next] = 1) continue;
		used[next] = 1;
		dfs(next);
		used[next] = 0;
	}
}

int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);
	cin >> n;
	used[0] = 1;
	dfs(0);

	return 0;
}