#include <iostream>
#include <vector>
using namespace std;
vector<int> copyReal;
vector<int> real;
int N;
int Po = 1;
void clean(int Stu) {
	// ù ������ ���� ��,
	if (0 == Stu) {
		copyReal.push_back(Po);
		Po++;
		
		for (int i = 0; i < real.size(); i++) {
			copyReal.push_back(real[i]);
		}
			real.clear();

		for (int i = 0; i < copyReal.size(); i++) {
			real.push_back(copyReal[i]);
		}
		return;
	}//������ ������ ������ ��
	else if (Stu == real.size()) {
		real.push_back(Po);
		Po++;
		return;
	}//�߰� ������ ������ ��
	else {
		for (int i = 0; i < Stu; i++) {
			copyReal.push_back(real[i]);
		}
		copyReal.push_back(Po);
		Po++;
		for (int i = Stu; i < real.size(); i++) {
			copyReal.push_back(real[i]);
		}
			real.clear();
		for (int i = 0; i < copyReal.size(); i++) {
			real.push_back(copyReal[i]);
		}
		return;
	}
	return;
}


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	// 1. ó���� ���� �ִ� ������ ù �ڸ�
	int a;
	cin >> a;
	real.push_back(1);

	Po++;
	// 2. ���ں��� �Է� ���� ������ Size()-N; ������ �ְ�,
	//    �� �տ�, �ڿ� �ֱ�
	for (int i = 1; i < N; i++) {
		int Num;
		cin >> Num;
		Num = real.size() - Num;
		// 2-1 �����ϴ� �Լ�
		clean(Num);
		// copy ����
		copyReal.clear();
	}

	for (int i = 0; i < real.size(); i++) {
		cout << real[i]<<" ";
	}

	return 0;
}