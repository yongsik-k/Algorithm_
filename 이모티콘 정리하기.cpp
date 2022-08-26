#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	string emti;
	cin >> emti;
	while (1) {
		int a = emti.find("((", 0);
		if (a == -1) break;
		emti.erase(a, 2);
		emti.insert(a, "(");

	}
	while (1) {
		int b = emti.find("))", 0);
		if (b == -1) break;
		emti.erase(b, 2);
		emti.insert(b, ")");

	}
	while (1) {
		int c = emti.find("^^^", 0);
		if (c == -1)break;
		emti.erase(c, 3);
		emti.insert(c, "^^");
	}
	int p = 0;
	while (1) {
		int d = emti.find('^', p);
		if (d == -1)break;
		int e = emti.find('^', d + 1);
		if ((e - d) == 2) {
			emti.erase(d + 1, 1);
			emti.insert(d + 1, "_");
		}
		p = e + 1;
	}
	cout << emti;
	return 0;
}