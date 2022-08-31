#include <iostream>
using namespace std;
int parent[10];
int GroupCnt[10]; // index : node��ȣ, value : �ش� node�� '��ǥ�� ��'
				  // �ش� �׷쿡 '�� ��' �� �ִ°�?
int Find(int now) {
	if (parent[now] == now)
		return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) { // �׷쿡 ��ȭ�� �ִ� �κ�
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)return; //A�� B�� �̹� ���� �׷��̾��� <- �ƹ��͵� ���� ����� ����
	//A�� B�� �ٸ� �׷��� �ܿ�
	//pA�� �������� ��ǥ�� ����
	parent[pB] = pA; // ��ǥ�� 1������ ����
	GroupCnt[pA] += GroupCnt[pB]; // pB�� ���� �ִ� ������ ���� ��ǥ�� pA���� �Ѱ���
	GroupCnt[pB] = 0;// pB�� '��ǥ���� ������ ��' ��ǥ�� �ƴϹǷ� ������ ����
}

int main() {
	for (int i = 0; i < 10; i++) {
		parent[i] = i; //�ڱ��ڽ��� ��ǥ��
		//GroupCnt �ʱ�ȭ
		GroupCnt[i] = 1; //��ΰ� '�ڱ��ڽ�'�� ��ǥ�ϱ� �� �׷츶�� 1���� ����
	}

	Union(1, 2);
	Union(2, 3);
	Union(1, 4);
	cout << GroupCnt[Find(2)] << '\n'; // �׷쿡 �ο����ϱ� ��ǥ���� ������� ��.
	Union(2, 5);
	Union(6, 7);
	Union(7, 8);
	Union(5, 8);
	cout << GroupCnt[(Find(3))];
	return 0;
}