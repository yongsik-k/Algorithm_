#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	unordered_map<int, int> um;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		um[a]++;
	}
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (um.count(a)) {
			cout << um[a] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}


	return 0;
}