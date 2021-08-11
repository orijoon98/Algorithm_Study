#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int n, m, k;
    cin>>n>>m;
    int** numbers = new int* [n];
    for(int i=0;i<n;i++){
        numbers[i] = new int [m];
        for(int j=0;j<m;j++){
            cin>>numbers[i][j];
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int a, b, c, d;
        int sum = 0;
        cin>>a>>b>>c>>d;
        for(int i=a-1;i<c;i++){
            for(int j=b-1;j<d;j++){
                sum += numbers[i][j];
            }
        }
        cout<<sum<<"\n";
    }
}
