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
	// 1. Round ����.
	for (int i = 0; i < N; i++) {
		// 2. A�� B ���� �Է¹ް�, ���� �� Ƚ���� ��ȣ�� �Է� �ް�, DAT�� ����.
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
		// 3. 4,3,2,1 �������, DAT�� ���ϰ�, ���ڸ� ����.
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
		// 4. �ʱ�ȭ
		clear();
	}

	
	


	return 0;
}