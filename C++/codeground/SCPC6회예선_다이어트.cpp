#include <iostream>
#include <algorithm>
using namespace std;

int T, N, K, ans;
int A[200001], B[200001];

void Input() {
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N>>K;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        sort(A, A+N);
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        sort(B, B+N);
        ans = 0;
        for(int i=0;i<K;i++){
            ans = max(ans, A[i] + B[K-1-i]);
        }
        cout<<"Case #"<<i<<'\n';
        cout<<ans<<'\n';
    }
}

void Solution() {

}

int main() {
    Input();
    return 0;
}
