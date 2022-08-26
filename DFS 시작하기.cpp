#include <iostream>
using namespace std;
int cntNode;
int Arr[101][101];

void run(int now) {

	cout << now << " ";

	for (int next = 0; next < cntNode; next++) {
		if (Arr[now][next] == 0)continue;
		run(next);

	}
}

int main() {

	cin >> cntNode;
	for (int i = 0; i < cntNode; i++) {
		for (int j = 0; j < cntNode; j++) {
			cin >> Arr[i][j];
		}
	}

	run(0);

	return 0;
}