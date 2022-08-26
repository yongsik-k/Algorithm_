#include <iostream>
#include <unordered_map>
using namespace std;

// ID를 기반으로 해당 ID를 갖는 사람의 이름과 PW를 가져오는 프로그램
// 첫 번째 줄에 등록된 ID, PW, Name이 몇세트 있는지
//해당 세트의 개수만큼 ID, PW, name을 각각 입력받음
//이어지는 마지막줄에 id를 입력하면 해당 id의 사람에 대한 이름과 pw를 출력


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