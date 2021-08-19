#include <bits/stdc++.h>

#define endl "\n"
#define MAX 5
using namespace std;

int MAP[MAX][MAX][MAX];
int C_MAP[MAX][MAX][MAX];
int Maze_Order[MAX];
int Turn_Order[MAX];
bool Select[MAX];
bool Visit[MAX][MAX][MAX];
int Answer = 987654321;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };

void Input()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                cin >> MAP[i][j][k];
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        Maze_Order[i] = -1;
        Turn_Order[i] = -1;
    }
}

void Copy_MAP()
{
    for (int i = 0; i < MAX; i++)
    {
        int Idx = Maze_Order[i];
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                C_MAP[i][j][k] = MAP[Idx][j][k];
            }
        }
    }
}

void Actual_Turning(int T, int Idx)
{
    if (T == 0) return;
    else if (T == 1)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (i == j) continue;
                if (MAP[Idx][i][j] == 0)
                {
                    C_MAP[Idx][4 - j][i] = 0;
                    C_MAP[Idx][i][j] = 1;
                }
            }
        }
    }
    else if (T == 2)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (i == j) continue;
                if (MAP[Idx][i][j] == 0)
                {
                    C_MAP[Idx][4 - i][4 - j] = 0;
                    C_MAP[Idx][i][j] = 1;
                }
            }
        }
    }
    else if (T == 3)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (i == j) continue;
                if (MAP[Idx][i][j] == 0)
                {
                    C_MAP[Idx][j][4 - i] = 0;
                    C_MAP[Idx][i][j] = 1;
                }
            }
        }
    }
}

int BFS(int A[MAX][MAX][MAX])
{
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    Visit[0][0][0] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int h = Q.front().second.first;
        int Cnt = Q.front().second.second;
        Q.pop();

        if (x == MAX - 1 && y == MAX - 1 && h == MAX - 1)
        {
            return Cnt;
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nh = h + dh[i];

            if (nx >= 0 && ny >= 0 && nh >= 0 && nx < MAX && ny < MAX && nh < MAX)
            {
                if (A[nh][nx][ny] == 1 && Visit[nh][nx][ny] == false)
                {
                    Visit[nh][nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(nh, Cnt + 1)));
                }
            }
        }
    }
    return -1;
}

void Make_Maze()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                C_MAP[i][j][k] = 1;
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        int Idx = Maze_Order[i];
        int Turn = Turn_Order[i];

        if (Turn == 0)
        {
            for (int x = 0; x < MAX; x++)
            {
                for (int y = 0; y < MAX; y++)
                {
                    C_MAP[i][x][y] = MAP[Idx][x][y];
                }
            }
        }
        else if (Turn == 1)
        {
            for (int x = 0; x < MAX; x++)
            {
                for (int y = 0; y < MAX; y++)
                {
                    if (MAP[Idx][x][y] == 0)
                    {
                        C_MAP[i][y][4 - x] = 0;
                    }
                }
            }
        }
        else if (Turn == 2)
        {
            for (int x = 0; x < MAX; x++)
            {
                for (int y = 0; y < MAX; y++)
                {
                    if (MAP[Idx][x][y] == 0)
                    {
                        C_MAP[i][4 - x][4 - y] = 0;
                    }
                }
            }
        }
        else if (Turn == 3)
        {
            for (int x = 0; x < MAX; x++)
            {
                for (int y = 0; y < MAX; y++)
                {
                    if (MAP[Idx][x][y] == 0)
                    {
                        C_MAP[i][4 - y][x] = 0;
                    }
                }
            }
        }
    }
}

void Make_Maze_Turn_Order(int Cnt)
{
    if (Cnt == MAX)
    {
        Make_Maze();
        if (C_MAP[0][0][0] == 1 && C_MAP[4][4][4] == 1)
        {
            memset(Visit, false, sizeof(Visit));
            int Temp_Result = BFS(C_MAP);
            if (Temp_Result != -1)
            {
                if (Temp_Result < Answer) Answer = Temp_Result;
            }
        }
        return;
    }

    for (int Turn = 0; Turn < 4; Turn++)
    {
        Turn_Order[Cnt] = Turn;
        Make_Maze_Turn_Order(Cnt + 1);
    }
}

void Make_Maze_Order(int Cnt)
{
    if (Cnt == MAX)
    {
        Make_Maze_Turn_Order(0);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        Maze_Order[i] = Cnt;
        Make_Maze_Order(Cnt + 1);
        Maze_Order[i] = -1;
        Select[i] = false;
    }
}

pair<int, bool> Check_MAP_State()
{
    pair<int, bool> Temp;
    bool Flag;

    for (int Idx = 0; Idx < 2; Idx++)
    {
        Flag = true;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                for (int k = 0; k < MAX; k++)
                {
                    if (MAP[i][j][k] != Idx)
                    {
                        Flag = false;
                        break;
                    }
                }
                if (Flag == false) break;
            }
            if (Flag == false) break;
        }

        if (Flag == true)
        {
            Temp.first = Idx;
            Temp.second = Flag;
            return Temp;
        }
    }
    Temp.first = -1;
    Temp.second = false;
    return Temp;
}

void Solution()
{
    pair<int, bool> Temp;
    Temp = Check_MAP_State();
    if (Temp.second == true)
    {
        if (Temp.first == 0)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            cout << "12" << endl;
            return;
        }
    }
    Make_Maze_Order(0);
    if (Answer == 987654321) Answer = -1;
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}