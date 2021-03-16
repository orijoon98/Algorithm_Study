#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long

int doll[500];

int main() {
    FAST;
    int n, k; cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>doll[i];
    }
    int sum = 0;
    double disp;
    double small = 9876543210;
    for(k=k;k<=n;k++){
        for(int i=0;i<=n-k;i++){
            disp = 0;
            sum = 0;
            for(int j=i;j<i+k;j++){
                sum += doll[j];
            }
            double avg = sum / (double)k;
            for(int j=i;j<i+k;j++){
                disp += (doll[j] - avg) * (doll[j] - avg);
            }
            small = min(small, sqrt(disp/(double)k));
        }
    }
    cout.precision(11);
    cout<<small;
}
