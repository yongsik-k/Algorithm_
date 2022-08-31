#include <iostream>
#include <string>

using namespace std;

int used[100] = {0};
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int N;
char path[100];
int cnt = 0;
int a = 0;
string AA;
void run(int lev) {
	if (lev == 4) {
		string a = path;
		if (a == AA) {
			cnt++;
			cout << cnt<<'\n';
			return;
		}
		cnt++;
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (lev >= 4) { lev = 4; }
		path[lev] = 'A'+i;
		run(lev + 1);
		a++;
	
	}
}



int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cnt = 0;
		cin >> AA;
		run(0);
	}


	return 0;
}

// A-Z ±îÁö;