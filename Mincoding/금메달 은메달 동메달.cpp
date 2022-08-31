#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
	string name;
	int score;
	int order;
};

//t�� v�� ���� �� �� ���������� �� �ʿ䰡 �����.
//t�� ��� �������
//v�� ��� �������

//t�� �������� �� ���ʿ� �־���ϴ� ���̶��? 1 ����
//�ƴϸ� 0 ����

//"�񱳱�"
//���ذ� �ʿ�������������
bool compare(Node t, Node v) {
	if (t.score > v.score) return 1;
	if (t.score < v.score) return 0;

	if (t.order > v.order) return 1;
	return 0;
}

int main() {
	int num;
	cin >> num;

	vector<Node> alist;

	for (int i = 0; i < num; i++) {
		string name;
		int score;

		cin >> name >> score;
		alist.push_back({ name, score,i });

		sort(alist.begin(), alist.end(), compare);

		for (int j = 0; j < alist.size(); j++) {
			if (j == 3) break;
			cout << alist[j].name << " ";
		}
		cout << endl;
	}


	return 0;
}