#include <iostream>
#include <vector>

using namespace std;

vector<int> alist;

int N;

int main(){
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		alist.push_back(temp);
	}
	int max = -2134567890;
	int indexX =0;
	int indexy =0;
	for (int i = 1; i < alist.size(); i++) {
		if (alist[i] > alist[i - 1]) {
			int gap = alist[i] - alist[i-1];
			if (max < gap) {
				max = gap;
				indexX = i;
				indexy = i+1;
			}
		}
		
	}
	if (indexX == 0 && indexy == 0) {
		cout << "0";
		return 0;
	}
	cout << indexX << " " << indexy;
	return 0;
}