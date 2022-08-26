#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


unordered_map<string, vector<int>> a;

int main() {


	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		string team;
		int score;
		cin >> team >> score;
		a[team].push_back(score);
	}


	string coco, friends;
	cin >> coco >> friends;
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < a[coco].size(); i++) {
		sum1 += a[coco][i];
	}

	for (int i = 0; i < a[friends].size(); i++) {
		sum2 += a[friends][i];
	}

	cout << a[coco].size() << " " << sum1 << '\n';
	cout << a[friends].size() << " " << sum2 << '\n';

	if (sum1 > sum2) {
		cout << coco;
	}
	else {
		cout << friends;
	}


	return 0;
}