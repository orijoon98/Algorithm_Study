#include <bits/stdc++.h>
#define endl "\n"
#define MAX 55
#define INF 2e9
using namespace std;

int N, M, Answer;
int MAP[MAX][MAX];
int Sum[MAX][MAX];
int Memo[MAX][MAX][MAX][MAX];

int Min(int A, int B) { if (A < B) return A; return B; }

void Initialize()
{
    memset(Sum, 0, sizeof(Sum));
    memset(Memo, -1, sizeof(Memo));
}

void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

void Calculate_Sum()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + MAP[i][j];
        }
    }
}

int DFS(int x, int y, int Ex, int Ey)
{
    if (x == Ex && y == Ey) return 0;
    if (Memo[x][y][Ex][Ey] != -1) return Memo[x][y][Ex][Ey];

    Memo[x][y][Ex][Ey] = INF;
    int Current_Sum = Sum[Ex][Ey] - Sum[x - 1][Ey] - Sum[Ex][y - 1] + Sum[x - 1][y - 1];
    for (int i = x; i < Ex; i++)
    {
        int Result1 = DFS(x, y, i, Ey);
        int Result2 = DFS(i + 1, y, Ex, Ey);
        Memo[x][y][Ex][Ey] = Min(Memo[x][y][Ex][Ey], Result1 + Result2 + Current_Sum);
    }
    for (int i = y; i < Ey; i++)
    {
        int Result1 = DFS(x, y, Ex, i);
        int Result2 = DFS(x, i + 1, Ex, Ey);
        Memo[x][y][Ex][Ey] = Min(Memo[x][y][Ex][Ey], Result1 + Result2 + Current_Sum);
    }

    return Memo[x][y][Ex][Ey];

}

void Solution()
{
    Calculate_Sum();
    Answer = DFS(1, 1, N, M);
}

void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}