#include <iostream>
#include<vector>
using namespace std;
struct Coord {
    int row, col;
};
int N, W, H; // �Է¿��� �ʱ�ȭ
int MAP[20][20]; // �Է¿��� �ʱ�ȭ
int copyMAP[20][20]; // makeCopy���� �ʱ�ȭ
vector<int> path; // dfs���� ����ϸ� �ٽ� ����
int ans = 2134567890; // <- ���� �ʱ�ȭ

void init() {
    ans = 2134567890;
}

void input()
{
    cin >> N >> W >> H;
    for (int row = 0; row < H; row++)
        for (int col = 0; col < W; col++)
            cin >> MAP[row][col];
}

void makeCopy() // ���� map -> copy������ ����
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            copyMAP[i][j] = MAP[i][j];
}

void boom(Coord now) // now : �̹��� ���� ��ǥ
{
    int boomRange = copyMAP[now.row][now.col];
    copyMAP[now.row][now.col] = 0; // ������ ������

              // ��,��,��,��
    int dr[] = { -1,1, 0,0 }; // ����
    int dc[] = { 0,0,-1,1 }; // ����
    for (int i = 0; i < 4; i++)
    {
        for (int dist = 1; dist < boomRange; dist++)
        {
            int nr = now.row + dr[i] * dist;
            int nc = now.col + dc[i] * dist;
            if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
            if (copyMAP[nr][nc] == 0) continue;
            boom({ nr, nc });
        }
    }
}// boom 1��

void Gravity()
{
    for (int col = 0; col < W; col++)
    {
        int lastZero = H - 1;
        for (int row = H - 1; row >= 0; row--)
        {
            if (copyMAP[row][col] != 0)
            {
                int temp = copyMAP[row][col];
                copyMAP[row][col] = copyMAP[lastZero][col];
                copyMAP[lastZero][col] = temp;
                lastZero--;
            }
        }
    }
}

void simul() {
    // path�� �̿��Ͽ� �� turn���� ������ ����߸�
    makeCopy();
    for (int i = 0; i < N; i++) // i : turn
    {
        int col = path[i];
        for (int row = 0; row < H; row++)
        {
            if (copyMAP[row][col])
            {
                boom({ row, col });
                break;
            }
        }
        Gravity();
    }
}

int remainCnt()
{
    int cnt = 0;
    for (int row = 0; row < H; row++)
        for (int col = 0; col < W; col++)
            if (copyMAP[row][col]) cnt++;
    return cnt;
}
void dfs(int now) // now : ���� ���� or turn
// dfs : �� turn���� ������ ����߸� ��ġ �̱�
{
    if (now >= N) // 0~3������ ���������� �̰� �� ����
    {
        simul();
        ans = min(ans, remainCnt());
        return;
    }
    for (int i = 0; i < W; i++)
    {
        path.push_back(i); // i���� �̾Ҵٶ�� ���
        dfs(now + 1);
        path.pop_back(); // �̹��� ����ߴ��� ����, ����
    }
}

int solution()
{
    // N���� ������ ����߸� ��ġ
    // N���� �ֻ���, �ֻ��� �� : 0~col-1
    // ���� �� �մ� ����� ��

    dfs(0);
    return ans;
}

int main()
{
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();
        cout << "#" << tc << " " << solution() << "\n";
    }
    return 0;
}