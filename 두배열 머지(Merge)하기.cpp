#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int Arr[4];
int Arr2[4];
vector<int> result;
int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 4; i++) {
		cin >> Arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> Arr2[i];
	}

	int a = 0, b = 0;

	while (1) {
		if (a == 4) {
			for (int i = b; i < 4; i++) {
				result.push_back(Arr2[b]);
				b++;
				if (b == 4) {
					for (int i = 0; i < result.size(); i++) {
						cout << result[i] << " ";
					}

				} return 0;
			}
		}

		if (b == 4) {
			for (int i = a; i < 4; i++) {
				result.push_back(Arr[a]);
				a++;
			}
			if (a == 4) {
				for (int i = 0; i < result.size(); i++) {
					cout << result[i] << " ";
				}

				return 0;
			}
		}

		if (Arr[a] >= Arr2[b]) {
			result.push_back(Arr2[b]);
			b++;
		}
		else if (Arr[a] < Arr2[b]) {
			result.push_back(Arr[a]);
			a++;
		}

	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}


	return 0;
}