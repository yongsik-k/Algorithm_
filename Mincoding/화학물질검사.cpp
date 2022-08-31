#include <iostream>
#include <string>
using namespace std;
string logM;

int percent(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	int cnt = 0, cnt2=0;
	int a=0, b=0;
	//대문자 ok
	//소문자 ok
	
	while (1) {
		int count = str.find("PASS",a);
		if (count == -1)break;
		cnt++;
		a = count + 1;
	}
	while (1) {
		int count2 = str.find("FAIL", b);
		if (count2 == -1)break;
		cnt2++;
		b = count2 + 1;
	}
	int ant= (cnt)*100/(cnt + cnt2);

	return ant;
}


int main() {
	cin >> logM;
	int a =percent(logM);
	cout << a<<"%";
	return 0;
}