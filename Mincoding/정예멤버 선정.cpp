#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> A_;
vector<int> B_;
vector<int> C_;

int A[3][3] = {
	{2,6,3},
	{7,1,1},
	{3,4,2}
};
int B[2][4] = {
	{6,4,2,4},
	{1,1,5,8}
};
int C[2][3] = {
	{9,2,3},
	{4,2,1}
};

int result[3][3];

int main() {
	//A
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A_.push_back(A[i][j]);
		}
	}
	sort(A_.begin(), A_.end());
	int a = 0;
	for (int i = A_.size() - 1; i >= 0; i--) {
		if (A_[i] != 0) {
			result[0][a] = A_[i];
			a++;
			if (a == 3) {
				break;
			}
		}
	}

	//B
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			B_.push_back(B[i][j]);
		}
	}
	sort(B_.begin(), B_.end());

	int b = 0;
	for (int i = 0; i < B_.size(); i++) {
		if (B_[i] != 0) {
			result[1][b] = B_[i];
			b++;
			if (b == 3) {
				break;
			}
		}
	}

	//C
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			C_.push_back(C[i][j]);
		}
	}
	sort(C_.begin(), C_.end());
	int c = 0;
	for (int i = 0; i < C_.size(); i++) {
		if (c == 2) {
			result[2][2] = C_[C_.size() - 1];
			break;
		}
		if (C_[i] != 0) {
			result[2][c] = C_[i];
			c++;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << result[i][j] << " ";
		}cout << '\n';
	}

	return 0;
}