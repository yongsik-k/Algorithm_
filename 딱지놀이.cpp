#include <iostream>
using namespace std;
int datA[5] = {0};
int datB[5] = {0};
void clear() {
	for (int i = 0; i < 5; i++) {
		datA[i] = 0;
		datB[i] = 0;
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;
	// 1. Round 설정.
	for (int i = 0; i < N; i++) {
		// 2. A와 B 각각 입력받고, 각각 총 횟수와 번호를 입력 받고, DAT에 저장.
		int numA;
		cin >> numA;
		for (int i = 0; i < numA; i++) {
			int ddak;
			cin >> ddak;
			datA[ddak]++;
		}
		int numB;
		cin >> numB;
		for (int i = 0; i < numB; i++) {
			int ddakB;
			cin >> ddakB;
			datB[ddakB]++;
		}
		// 3. 4,3,2,1 순서대로, DAT를 비교하고, 승자를 낸다.
		for (int i = 4; i >= 1; i--) {
			if (datB[i] > datA[i]) {
				cout << 'B' << '\n';
				break;
			}
			else if (datB[i] < datA[i]) {
				cout << 'A' << '\n';
				break;
			}
			else if (datB[i] == datA[i]) {
				if (i == 1) {
					cout << 'D'<<'\n';
				}
				continue;
			}
		}
		// 4. 초기화
		clear();
	}

	
	


	return 0;
}