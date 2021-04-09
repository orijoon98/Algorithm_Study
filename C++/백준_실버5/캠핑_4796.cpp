#include <iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    FAST;
    int L = -1, P = -1, V = -1;
    int cnt = 1;
    int n = -1;
    while(true){
        cin>>L>>P>>V;
        if(L == 0 && P == 0 && V == 0) break;
        if(V % P > L) n = L;
        else n = V % P;
        cout<<"Case "<<cnt<<": "<<((int)(V/P))*L + n<<"\n";
        cnt++;
    }
}
