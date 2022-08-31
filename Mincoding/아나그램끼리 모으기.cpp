#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
unordered_map<string, int> um;
vector<string> a;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string Alpha;
		cin >> Alpha;
		a.push_back(Alpha);
	}
	int max = -2134567890;
	for (int i = 0; i < a.size(); i++) {
		sort(a[i].begin(), a[i].end());
		um[a[i]]++;
		if (um[a[i]] > max) {
			max = um[a[i]];
		}
	}
	cout << max;


	return 0;
}