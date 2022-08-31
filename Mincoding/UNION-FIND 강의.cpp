#include <iostream>
using namespace std;

int parent[10];

//��ǥ�� ã���ִ� �Լ�
int Find(int now) { //dfsó�� ����

	if (parent[now] == now) // ���������� ��ǥ���� ���� ��(now�� ��ǥ�� ��)
		return now;  //Find()�� ����ô� ���� now�� ��ǥ�� ��� �˷���

	int root = Find(parent[now]); // �θ�� Ÿ�� �ö󰡶�.
	// now�� ��ǥ root�� �޾ƿ�

	/////////
	parent[now] = root; // now�� ��ǥ�� �θ� root������? ��� ǥ��
						// �ӵ��� ���̴� ����!
	////////
	return root; // now�� ��ǥ�� root��! ��� �˷���
}

//�׷��� �����ִ�(�ϳ��� �����ִ�) �Լ�
void Union(int A, int B) { // �̰� �빮�ڷ� ��� �ҹ��ڴ� �������Ѵ�.
	int pA = Find(A); // A�� ��ǥ
	int pB = Find(B); // B�� ��ǥ
	parent[pB] = pA;


}


int main() {
	// 1. �� node�� �ڱ��ڽ��� ��ǥ��. (��� �и�)
	for (int i = 0; i <= 6; i++) {
		parent[i] = i;
	}
	// 2. ���ս�Ű��
	Union(1, 2);
	Union(1, 3);
	Union(4, 5);
	Union(3, 5);

	// 3. ���� 2�� 5�� ���� �׷��ΰ�? �� Ȯ���ϰ� �ʹٸ�?
	if (Find(2) == Find(5)) {
		//parent[2] == parent[5]��� �ϸ� �ȵȴ� �ֳĸ� ���� �׷����� 
		//���°��� �ٽ��ΰǵ�, parent[5] �� �θ�� 4�ϱ�.
		//��������δ� �����׷����� Ȯ���Ϸ��� �ְ� ������ ã�ƾ� ��.
		cout << "Same";
	}
	else {
		cout << "diff";
	}

	return 0;
}