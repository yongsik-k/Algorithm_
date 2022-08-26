#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int Arr[6][6] = {
	{0,0,1,1,0,1},
	{0,0,0,1,1,1},
	{0,0,0,0,1,1},
	{0,0,0,0,0,0},
	{1,0,0,0,0,1},
	{0,0,0,0,0,0}
};

int used[10];

void dfs(int now) {
	cout << now << " ";
	for (int next = 0; next < 6; next++) {
		if (Arr[now][next] == 0) continue;
		if (used[next] == 1)continue;
		used[next] = 1;
		dfs(next);
	}
}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	used[n] = 1;
	dfs(n);


	return 0;
}