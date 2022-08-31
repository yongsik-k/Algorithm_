#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int Arr[6] = { 1,5,4,2,-5,-7 };

int main() {
	int n;
	cin >> n;
	sort(Arr, Arr + 6, greater<int>());
	cout << Arr[n - 1];

	return 0;
}