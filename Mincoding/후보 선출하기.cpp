#include <iostream>
#include <string>
using namespace std;

int level;
string hubo;
char path[10];

void run(int lev) {
	
	if (lev == level) {
		cout << path<< '\n';
		return;
	}

	for (int i = 0; i < hubo.length(); i++) {
		path[lev] = hubo[i];
		run(lev + 1);
	}



}


int main() {
	cin >> hubo;
	cin >> level;

	run(0);
	
	return 0;
}