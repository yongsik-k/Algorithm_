#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
vector<int> alist;

int main() {
	FILE* freinput = freopen("input.txt", "rt", stdin);
	int stu, bet;
	cin >> stu >> bet;
	for (int i = 0; i < stu; i++) {
		int temp;
		cin >> temp;
		alist.push_back(temp);
	}

	for (int i = 0; i < bet; i++) {
		int A, B;
		cin >> A >> B;
		double sum = 0;
		for (int j = A - 1; j <= B - 1; j++) {
			sum += alist[j];
		}
		//이거 소숫점 계산
		cout << fixed;
		cout.precision(2);
		cout << sum / (B - A + 1) << '\n';

	}


	return 0;
}