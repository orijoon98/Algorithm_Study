#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n, k;
    cin>>n;
    char **mirror = new char *[n];
    for(int i=0;i<n;i++){
        mirror[i] = new char[n];
        cin>>mirror[i];
    }
    cin>>k;
    switch (k) {
        case 2:
            for(int i=0;i<n;i++){
                for(int j=n-1;j>=0;j--){
                    cout<<mirror[i][j];
                    if(j==0){cout<<"\n";}
                }
            }
            break;
        case 3:
            for(int i=n-1;i>=0;i--){
                for(int j=0;j<n;j++){
                    cout<<mirror[i][j];
                    if(j==n-1){cout<<"\n";}
                }
            }
            break;
        default://1
            for(int i=0;i<n;i++){cout<<mirror[i]<<"\n";}
            break;
    }
}
