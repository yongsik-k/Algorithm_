#include <iostream>
using namespace std;
int Arr[101][101] = { 0 };
int H, W;
int N;
int dat[101] = {0};
int Max = -2134567890;
int findX;
int findY;
int finishX;
int finishY;
int makeArea() {
	int ret = 0;
	int a = 0;
	int b = 0;
	while (1) {
		if (a == W - 1) {
			break;
		}
		for (int i = a; i < W; i++) {
			if (Arr[0][i] == 2 || (i == W - 1)) {
				findX = i;
				while (1) {
					if (b == H - 1) {
						break;
					}
					for (int i = b; i < H; i++) {
						if (Arr[i][0] == 1 || (i == H - 1)) {
							findY = i;
							break;
						}
					}
					for (int i = a; i <= findY; i++) {
						for (int j = b; j <= findX; j++) {
							ret++;
						}
					}
					if (Max < ret) {
						Max = ret;
						ret = 0;
					}
					b = findY;
				}
			}
		}
		a = findX;
			
	}

	return Max;
}


void inputY() {
	for (int i = 0; i < 101; i++) {
		if (dat[i] == 1) {
			for (int j = 0; j < H; j++) {
				Arr[j][i]=2;
			}
		}
	}
}

void inputX(int posi, int num) {
	if (posi == 0) {
		for (int i = 0; i < W; i++) {
			Arr[num][i] = 1;
		}
	}
	else if (posi == 1) {
		dat[num] = 1;
	}
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> W>>H;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int position, number;
		cin >> position >> number;
		inputX(position,number-1);
	}
		inputY();
	// �� ���ķ� ���̸� ���� ��.
	//���̸� ȯ���� �� �ִ� �Լ��� �����ߴٰ� �����Ѵ�.
		
		int result = makeArea();
	//���� ��� �� ���
		cout << result;


return 0;
}