#include <iostream>
using namespace std;

int parent[10];

int Find(int now) {
	if (parent[now] = now)return now;
	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}
void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)return;
	parent[pB] = pA;
}
int main() {
	for (int i = 0; i < 10; i++) {
		parent[i] = i;
	}

	Union(3, 4);
	Union(3, 5);
	Union(5, 1);
	Union(8, 9);

	if (Find(3) == Find(4)) {
		cout << "같은그룹";
	}
	else {
		cout << "다른그룹";
	}


	return 0;
}