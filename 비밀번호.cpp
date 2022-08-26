#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> alist;
string Str;
void blood(int a, int b) {
	while (1) {
		if (a == -2134567890) {
			a--;
			continue;
		}
		if (b == -2134567890) {
			b++;
			continue;
		}
		if (Str[a] == Str[b]) {
			Str[a] = -2134567890;
			Str[b] = -2134567890;
			a--;
			b++;
			continue;
		}
		if (a < 0 || b == Str.length() || Str[a] != Str[b])break;

	}
	return;
}

int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);
	int ans = 0;
	int idx = 1;
	int A;
	for (int i = 0; i < 10; i++) {
		cin >> A;

		cin >> Str;
		int a = 0;
		while (1) {
			if (a == 3)break;
			for (int i = 0; i < Str.length(); i++) {
				if (i + 1 == Str.length()) {
					break;
				}
				if (Str[i] == Str[i + 1]) {

					Str[i] = -2134567890;
					Str[i + 1] = -2134567890;
					blood(i - 1, i + 2);

				}
			}
			a++;
		}

		cout << '#' << idx << " ";
		for (int i = 0; i < Str.length(); i++) {
			if (Str[i] == '.')continue;
			cout << Str[i];
		}
		cout << '\n';
		idx++;
	}
	return 0;
}