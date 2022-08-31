#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char parent[100];

int Find(int now) {
	if (parent[now] == now)
		return now;

	int root = Find(parent[now]);

	parent[now] = root;
	
	return root;
}



void Union(char A, char B) {
	char pA = Find(A);
	char pB = Find(B);
	parent[pB] = pA;
	return;
}



int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < 100; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		char A, B;
		cin >> A >> B;
		Union(A, B);
	}
	cout << "¹ß°ß";





	return 0;
}