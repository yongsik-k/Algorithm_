#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;
int Arr[6][6] = {
	{0,0,0,0,1,0},
	{1,0,1,0,0,1},
	{1,0,0,1,0,0},
	{1,1,0,0,0,0},
	{0,1,0,1,0,1},
	{0,0,1,1,0,0}
};

queue<int> q;
int used[10];
int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);

	int n;
	cin >> n;

	q.push(n);
	used[n] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " " << '\n';
		for (int next = 0; next < 6; next++) {
			if (Arr[now][next] == 0)continue;
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push(next);
		}
	}


	return 0;
}