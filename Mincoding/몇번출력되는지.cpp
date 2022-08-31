#include <iostream>
#include <string>
using namespace std;
int main() {
	int cnt = 0;
	string str;
	string fin;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		fin += str;
	}
	int a = 0;
	
	while (1) {
		int abc = fin.find("MCD", a);
		if (abc == -1)break;
		cnt++;
		a = abc + 1;	
	}
	cout << cnt;
	



	return 0;
}