#include <iostream>
using namespace std;

int parent[10];

//대표를 찾아주는 함수
int Find(int now) { //dfs처럼 만듦

	if (parent[now] == now) // 최종적으로 대표까지 왔을 때(now가 대표일 때)
		return now;  //Find()로 물어봤던 곳에 now가 대표다 라고 알려줌

	int root = Find(parent[now]); // 부모로 타고 올라가라.
	// now의 대표 root를 받아옴

	/////////
	parent[now] = root; // now의 대표가 부모가 root였구나? 라고 표시
						// 속도를 높이는 행위!
	////////
	return root; // now의 대표는 root다! 라고 알려줌
}

//그룹을 묶어주는(하나로 합쳐주는) 함수
void Union(int A, int B) { // 이거 대문자로 써라 소문자는 기존재한다.
	int pA = Find(A); // A의 대표
	int pB = Find(B); // B의 대표
	parent[pB] = pA;


}


int main() {
	// 1. 각 node가 자기자신이 대표다. (모두 분리)
	for (int i = 0; i <= 6; i++) {
		parent[i] = i;
	}
	// 2. 결합시키기
	Union(1, 2);
	Union(1, 3);
	Union(4, 5);
	Union(3, 5);

	// 3. 만약 2와 5가 같은 그룹인가? 를 확인하고 싶다면?
	if (Find(2) == Find(5)) {
		//parent[2] == parent[5]라고 하면 안된다 왜냐면 같은 그룹인지 
		//묻는것이 핵심인건데, parent[5] 면 부모는 4니까.
		//결론적으로는 같은그룹인지 확인하려면 최고 보스를 찾아야 해.
		cout << "Same";
	}
	else {
		cout << "diff";
	}

	return 0;
}