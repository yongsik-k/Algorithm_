#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> v2;
int main() {
	freopen_s(new FILE *, "input.txt", "r", stdin);
	int n;
	cin >> n;
	int Arr[20][20] = { 0 };
	int Arr2[20][20] = { 0 };
	//암호화 된 배열입력받기
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		int temp2;
		cin >> temp2;
		v2.push_back(temp2);
	}
	


	//암호를 배열에 넣기
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (v[i] == 1) {
				Arr[i][j] = 1;
				break;
			}
			if (v[i] % 2 == 1) {
				Arr[i][j] = 1;
			}
			else if (v[i] % 2 == 0) {
				Arr[i][j] = 0;
			}
			v[i] = v[i] / 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (v2[i] == 1) {
				Arr2[i][j] = 1;
				break;
			}
			if (v2[i] % 2 == 1) {
				Arr2[i][j] = 1;
			}
			else if (v2[i] % 2 == 0) {
				Arr2[i][j] = 0;
			}
			v2[i] = v2[i] / 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Arr[i][j] == 0 && Arr2[i][j] == 0) {
				cout << " ";
			}
			else cout << "#";
		}cout << endl;
	}

	int a123 = 1;
	return 0;
}