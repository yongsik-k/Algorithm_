#include <iostream>
#include <vector>
#include <string>

using namespace std;

int result[1001] = { 0 };

int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);
	vector<string> Arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		Arr.push_back(temp);
	}
	int a = n / 2;

	int limit = n / 2;
	if (limit % 2 == 1) {
		limit += 1;
	}
	for (int i = 0; i < limit; i++) {
		int a = i;
		int b = limit + i;
		if (b == n)break;
		cout << Arr[a] << " ";
		cout << Arr[b] << " ";

	}



	return 0;
}