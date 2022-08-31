#include <iostream>
#include <vector>
using namespace std;
int N, K; // N == 지도 크기 , K는 깍을 수 있는 크기
int Arr[10][10] = { 0 };
struct coord {
	int y, x;
};
vector<coord> pos;

void input() {
	cin >> N >> K;
	int max = -2134567890;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
			if (max < Arr[i][j]) {
				pos.clear();
			}
			if (max <= Arr[i][j]) {
				pos.push_back({ i,j });
				max = Arr[i][j];
			}
		}
	}
	return;
}
int used[10][10] = { 0 };

int dfs(coord now, int flag, int height) {
	int ret = 1;
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
		if (used[ny][nx] == 1)continue;
		used[ny][nx] = 1;
		if (height > Arr[ny][nx]) {
			ret = max(ret,
				dfs({ ny,nx }, flag, Arr[ny][nx]) + 1);
		}
		else if (flag == 0 && height > Arr[ny][nx] - K) {
			ret = max(ret, dfs({ ny, nx }, 1, height - 1) + 1);
		}
		used[ny][nx] = 0;
	}
	return ret;
}



int solution() {
	int ret = 0;
	for (int i = 0; i < pos.size(); i++) {
		coord st = pos[i];
		used[st.y][st.x] = 1;
		ret = max(ret, dfs(st, 0, Arr[st.y][st.x]));
		used[st.y][st.x] = 0;
	}


	return ret;
}



int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		input();
		int a = 2;
		cout << "#" << tc << " " << solution() << '\n';
	}





	return 0;
}