#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int evid[7] = { -1,0,0,1,2,4,4 };
int timeStamp[7] = { 8,3,5,6,8,9,10 };
int startIdx = -2134567890;
int arriveIdx = 0;
void dfs(int now) {
	if (now == 0) {
		cout << now << "��" << "index(���)" << '\n';
		return;
	}
	int next = evid[now];
	dfs(next);
	cout << now << "��" << "index" << "(" << timeStamp[now] << "��" << ")" << '\n';

}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	startIdx = N;
	dfs(startIdx);

	return 0;
}
//0��index(���)
//2��index(5��)
//4��index(8��)
//5��index(9��)