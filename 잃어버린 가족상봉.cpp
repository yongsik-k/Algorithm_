#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int path[5];
int Arr[8][8] = { //0Àº A
	{0,1,1,0,0,0,0,1},
	{0,0,0,0,0,0,0,0},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};

int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);

	char A;
	cin >> A;
	int a = A - 'A';
	int right = -2134567890;
	for (int i = 0; i < 8; i++) {
		if (Arr[i][a] == 1) {
			right = i;
			break;
		}
	}
	if (right == -2134567890) {
		cout << "¾øÀ½";
		return 0;
	}

	for (int i = 0; i < 8; i++) {
		if (i == a) continue;
		if (Arr[right][i] == 1) {
			cout << char(i + 'A') << " ";
		}
	}

	return 0;
}