#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Arr[6][6] = {
	{0,0,1,0,2,0},
	{5,0,3,0,0,0},
	{0,0,0,0,0,7},
	{2,0,0,0,8,0},
	{0,0,9,0,0,0},
	{4,0,0,7,0,0}
};
int used[10] = { 0 };
int sum = 0;
void dfs(int now) {
	cout << now << " " << sum << '\n';
	for (int next = 0; next < 6; next++) {
		if (Arr[now][next] == 0)continue;
		if (used[next] == 1)continue;
		sum += Arr[now][next];
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