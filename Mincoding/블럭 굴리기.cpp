#define _CRT_SECURE_NO_WARNINGS
//이거 솔직히 어떻게 푸는 지 모르겠어서 그냥 풀었어
#include <iostream>
using namespace std;

char result4[3][4] = {
	{"_54"},
	{"3__"},
	{"__1"}
};

char result1[3][4] = {
	{"_3_"},
	{"__5"},
	{"1_4"}
};
char result2[3][4] = {
	{"1__"},
	{"__3"},
	{"45_"}
};
char result3[3][4] = {
	{"4_1"},
	{"5__"},
	{"_3_"}
};

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int a;
	cin >> a;
	int real = a % 4;
	if (real == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << result1[i][j];
			}cout << '\n';
		}
	}
	else if (real == 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << result4[i][j];
			}cout << '\n';
		}
	}
	else if (real == 2) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << result2[i][j];
			}cout << '\n';
		}
	}
	else if (real == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << result3[i][j];
			}cout << '\n';
		}
	}


	return 0;
}