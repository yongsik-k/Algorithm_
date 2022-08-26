#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//char Model[5][4] =
//{
//	{"___"},
//	{"___"},
//	{"ATK"},
//	{"___"},
//	{"___"},
//};

string Model[5] =
{
	{"___"},
	{"___"},
	{"ATK"},
	{"___"},
	{"___"},
};



void UP(char A) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (Model[i][j] == A) {
				if ((i - 1) < 0)continue;
				char temp = Model[i][j];
				Model[i][j] = Model[i - 1][j];
				Model[i - 1][j] = temp;
				return;
			}
		}
	}
	return;
}
//
void DOWN(char A) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (Model[i][j] == A) {
				if ((i + 1) < 0)continue;
				char temp = Model[i][j];
				Model[i][j] = Model[i + 1][j];
				Model[i + 1][j] = temp;
				return;
			}
		}
	}
	return;
}

void LEFT(char A) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (Model[i][j] == A) {
				if ((j - 1) < 0)continue;
				char temp = Model[i][j];
				Model[i][j] = Model[i][j - 1];
				Model[i][j - 1] = temp;
				return;
			}
		}
	}
	return;
}

void RIGHT(char A) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (Model[i][j] == A) {
				if ((j + 1) < 0)continue;
				char temp = Model[i][j];
				Model[i][j] = Model[i][j + 1];
				Model[i][j + 1] = temp;
				return;
			}
		}
	}
	return;
}


int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 7; i++) {
		char A;
		string B;
		cin >> A;
		cin >> B;
		if (B == "UP") {
			UP(A);
		}
		else if (B == "DOWN") {
			DOWN(A);
		}
		else if (B == "LEFT") {
			LEFT(A);
		}
		else if (B == "RIGHT") {
			RIGHT(A);
		}

	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Model[i][j];
		}cout << '\n';
	}

	return 0;
}