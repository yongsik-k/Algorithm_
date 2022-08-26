#include <iostream>
#include <unordered_map>
using namespace std;

// ID�� ������� �ش� ID�� ���� ����� �̸��� PW�� �������� ���α׷�
// ù ��° �ٿ� ��ϵ� ID, PW, Name�� �Ʈ �ִ���
//�ش� ��Ʈ�� ������ŭ ID, PW, name�� ���� �Է¹���
//�̾����� �������ٿ� id�� �Է��ϸ� �ش� id�� ����� ���� �̸��� pw�� ���


struct Data {
	string Pw;
	string Name;
};

unordered_map<string, Data> ID2Data;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string ID, Pw, Name;
		cin >> ID >> Pw >> Name;
		ID2Data[ID] = { Pw,Name };
	}
	string ID;
	cin >> ID;
	cout << ID2Data[ID].Name << " " << ID2Data[ID].Pw;

	return 0;
}