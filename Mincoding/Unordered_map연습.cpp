#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
	unordered_map<string, int> um;
	vector<string> v = { "huhu", "hot", "bts", "mc", "hot", "hot" };
	string a;
	cin >> a;
	um[a]++;
	
	return 0;
}