#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, vector<int>> um;
int loguser = 1;
int user = 1;

void reg() {
	string id;
	int password;
	cin >> id >> password;
	if (um.count(id)) {
		cout << "reg fail" << '\n';
		return;
	}
	um[id].push_back(password);
	cout << "welcome " << user << '\n';
	user++;
	return;
}

void login() {
	string id;
	int password;
	cin >> id >> password;
	if (um[id].size() > 1) {
		if (um[id][1] == 1) {
			cout << "login fail" << '\n';
			return;
		}
	}

	if (um.count(id) || um[id][0] != password || um[id].size() > 1) {
		cout << "login fail" << '\n';
		return;
	}
	um[id].push_back(1);
	cout << "login " << loguser << '\n';
	loguser++;
}

void change() {
	string id;
	int origin;
	int newpass;
	cin >> id >> origin >> newpass;
	if (!um.count(id) || um[id][0] != origin) {
		cout << "change fail" << '\n';
		return;
	}
	if (um[id][0] == origin) {
		cout << "success" << '\n';
		um[id][0] = newpass;
		return;
	}
}

void logout() {
	string id;
	if (um.count(id)) {
		cout << "logout" << '\n';
		--loguser;
		um[id][1] = 0;
		return;
	}
	else {
		cout << "logout fail" << '\n';
		return;
	}
}

void bye() {
	string id;
	if (um.count(id) && um[id][1] == 1) {
		--loguser;
		cout << "bye " << loguser << '\n';
		um[id].clear();
		return;
	}
	else {
		cout << "bye fail" << '\n';
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string A;
		cin >> A;
		if (A == "reg") {
			reg();
		}
		else if (A == "login") {
			login();
		}
		else if (A == "change") {
			change();
		}
		else if (A == "logout") {
			logout();
		}
		else if (A == "bye") {
			bye();
		}

	}

	return 0;
}