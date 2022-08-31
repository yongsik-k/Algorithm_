#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> alist;
queue<int> q;
int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);

	int tc;
	for (int i = 0; i < 10; i++) {
		cin >> tc;

		for (int i = 0; i < 8; i++) {
			int temp;
			cin >> temp;
			q.push(temp);
		}

		int a = 1;
		while (1) {
			if ((q.front() - a) <= 0) {
				q.push(0);
				q.pop();
				break;
			}
			q.push(q.front() - a);
			q.pop();
			a++;
			if (a == 6) {
				a = 1;
			}
		}
		cout << '#' << tc << " ";
		for (int i = 0; i < 8; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << '\n';
	}
	return 0;
}