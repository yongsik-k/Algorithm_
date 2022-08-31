#include <iostream>
#include <vector>
using namespace std;
vector<int> copyReal;
vector<int> real;
int N;
int Po = 1;
void clean(int Stu) {
	// 첫 순위가 나올 때,
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
	}//마지막 순서가 나왔을 때
	else if (Stu == real.size()) {
		real.push_back(Po);
		Po++;
		return;
	}//중간 순서가 나왔을 때
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
	// 1. 처음에 들어가는 애는 무조건 첫 자리
	int a;
	cin >> a;
	real.push_back(1);

	Po++;
	// 2. 숫자별로 입력 받은 다음에 Size()-N; 범위에 넣고,
	//    그 앞에, 뒤에 넣기
	for (int i = 1; i < N; i++) {
		int Num;
		cin >> Num;
		Num = real.size() - Num;
		// 2-1 정리하는 함수
		clean(Num);
		// copy 정리
		copyReal.clear();
	}

	for (int i = 0; i < real.size(); i++) {
		cout << real[i]<<" ";
	}

	return 0;
}