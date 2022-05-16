#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

ll N, G, K;
vector<vector<ll>> unnecessary;
vector<vector<ll>> necessary;

void Input() {
    cin>>N>>G>>K;
    for (ll i = 0; i < N; i++) {
        ll S, L, O;
        cin>>S>>L>>O;
        vector<ll> v;
        v.push_back(S);
        v.push_back(L);
        v.push_back(O);
        (O == 1) ? unnecessary.push_back(v) : necessary.push_back(v);
    }
}

// day 일에 최대 K개 재료를 뺐을 때 세균수
ll Germ(ll day) {
    ll germ = 0;
    // 필수적인 재료들은 모두 세균수를 계산
    for (ll i = 0; i < necessary.size(); i++) {
        vector<ll> cur = necessary[i];
        germ += cur[0] * max((ll)1, day - cur[1]);
    }
    // 세균수가 높은 K 개를 제외하고 총 세균수에 합산
    vector<ll> ingredients;
    for (ll i = 0; i < unnecessary.size(); i++) {
        vector<ll> cur = unnecessary[i];
        ll tmp = cur[0] * max((ll)1, day - cur[1]);
        ingredients.push_back(tmp);
    }
    sort(ingredients.begin(), ingredients.end());
    for (ll i = 0; i < (ll)(ingredients.size()) - K; i++) {
        germ += ingredients[i];
    }
    return germ;
}

ll BinarySearch(ll size) {
    ll left = 1;
    ll right = size;
    ll middle = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        if (Germ(middle) <= G) left = middle + 1;
        else right = middle - 1;
    }
    return right;
};

void Solution() {
    cout<<BinarySearch(2000000000)<<endl;
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