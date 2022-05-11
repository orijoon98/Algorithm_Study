#include <bits/stdc++.h>
#define endl '\n'
#define MAX INT_MAX

using namespace std;

int N, ans = 0;
vector<vector<pair<int,int>>> dices;
vector<vector<bool>> flags;

void Input() {
    cin>>N;
    for (int i = 0; i < N; i++) {
        vector<pair<int,int>> dice;
        int a, b, c, d, e, f;
        cin>>a>>b>>c>>d>>e>>f;
        // 반대면 끼리 묶어서 입력 저장
        pair<int, int> x = make_pair(a, f);
        pair<int, int> y = make_pair(b, d);
        pair<int, int> z = make_pair(c, e);
        dice.push_back(x);
        dice.push_back(y);
        dice.push_back(z);
        dices.push_back(dice);
    }
}

void Solution() {
    // 1번 주사위 위아래 고정 3가지 경우의 수 체크
    for (int i = 0; i < 3; i++) {
        // 1번 주사위의 i번째 pair를 반대로 놓는 두 가지 경우의 수 확인
        for (int j = 0; j < 2; j++) {
            // 주사위 위 아래 고정 초기화
            flags.clear();
            for (int x = 0; x < N; x++) {
                vector<bool> flag(3, true);
                flags.push_back(flag);
            }
            // 1번 주사위부터 N번 주사위까지 위 아래 세팅
            flags[0][i] = false;
            int cur; // 주사위의 윗면
            if (j == 0) 
                cur = dices[0][i].first;
            else cur = dices[0][i].second;
            for (int x = 1; x < N; x++) {
                for (int y = 0; y < 3; y++) {
                    int a = dices[x][y].first;
                    int b = dices[x][y].second;
                    if (a == cur) {
                        flags[x][y] = false;
                        cur = b;
                        break;
                    }
                    if (b == cur) {
                        flags[x][y] = false;
                        cur = a;
                        break;
                    }
                }
            }
            // 위 아래 고정 면 제외하고 옆면 최대값 구하기
            int local_max = 0;
            for (int x = 0; x < N; x++) {
                int tmp = 0;
                for (int y = 0; y < 3; y++) {
                    if (!flags[x][y]) continue; // 위, 아래 면 제외
                    int num = max(dices[x][y].first, dices[x][y].second);
                    tmp = max(tmp, num); // 옆면 중 최대값
                }
                local_max += tmp;
            }
            ans = max(ans, local_max);
        }
    }
    cout<<ans<<endl;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}