#include <iostream>
#include <string>
using namespace std;

string name;

int isGo(string str) {
	if (str.find(name) == -1) {
		return 0;
	}
	return 1;
}


int main() {
	cin >> name;
	int num;
	cin >> num;
	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		if (isGo(str)) cout << "O" << "\n";
		else cout << "X" << "\n";
	}
	return 0;
}