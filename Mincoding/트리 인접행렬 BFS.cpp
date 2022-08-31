#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int Arr[6][6] = {
	{0,1,0,0,1,0},
	{0,0,1,0,0,1},
	{0,0,0,1,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
};
queue<int> q;
int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);

	int n;
	cin >> n;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";						// �̰� ���� ��������
		for (int next = 1; next <= 5; next++) { // �̰� �������� ����?
			if (Arr[now][next] == 0)continue;

			q.push(next);
		}
	}



	return 0;
}