#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n, k;
    cin>>n>>k;
    deque<double> v, v2;
    for(int i=0;i<n;i++){
        double num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    v2 = v;
    for(int i=0;i<k;i++){
        v.pop_back();
        v.pop_front();
    }
    double sum = 0;
    for(int i=0;i<v.size();i++) sum+=v[i];
    sum = sum / v.size();
    cout<<fixed;
    cout.precision(2);
    cout<<sum+0.00000001<<"\n";
    for(int i=0;i<k;i++){
        v2[i] = v2[k];
        v2[v2.size()-1-i] = v2[v2.size()-1-k];
    }
    sum = 0;
    for(int i=0;i<v2.size();i++) sum+=v2[i];
    sum = sum / v2.size();
    cout<<sum+0.00000001<<"\n";
}

