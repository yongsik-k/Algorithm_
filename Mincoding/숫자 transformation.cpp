#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Arr[3][4] = {
	{3,5,4,1},
	{1,1,2,3},
	{6,7,1,2}
};
int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (Arr[i][j] == A) {
				Arr[i][j] = B;
			}
			else if (Arr[i][j] == B) {
				Arr[i][j] = C;
			}
			else if (Arr[i][j] == C) {
				Arr[i][j] = D;
			}
			else if (Arr[i][j] == D) {
				Arr[i][j] = A;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << Arr[i][j] << " ";
		}cout << '\n';
	}

	return 0;
}