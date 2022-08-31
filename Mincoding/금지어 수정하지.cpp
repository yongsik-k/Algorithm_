#include <iostream>
#include <string>
using namespace std;

string before[5] = {
	"KFC",
	"MC",
	"BICMAC",
	"SHACK",
	"SONY",
};
string after[5] = {
"#BBQ#",
"#BBQ#",
"#MACBOOK#",
"#SHOCK#",
"#NONY#"
};
string isreal(string str){
	int index = 0;
	for (int i = 0; i < 5; i++) {
		while (1) {
			int a = str.find(before[i], index);
			if (a == -1)break;
			index = a + 1;
			str.erase(a, before[i].length());
			str.insert(a, after[i]);
		}

	}
	return str;
}

int main() {
	string str;
	cin >> str;
	cout<<isreal(str);
	return 0;
}