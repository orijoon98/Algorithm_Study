#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n, start, find, find_i=0, find_j=0;
    cin>>n;
    start = n/2;
    int** snail = new int*[n];
    for(int i=0;i<n;i++){
        snail[i] = new int[n];
    }
    snail[start][start] = 1;
    int a = start, b = start;
    int num = 2, cnt = 1;
    bool flag = true;
    while(flag){
        while(a != start - cnt){
            snail[--a][b] = num++;
            if(snail[0][0] == n*n){
                flag = false;
                break;
            }
        }
        if(flag){
            while(b != start + cnt){
                snail[a][++b] = num++;
            }
            while(a != start + cnt){
                snail[++a][b] = num++;
            }
            while(b != start - cnt){
                snail[a][--b] = num++;
            }
            cnt++;
        }
    }
    cin>>find;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<snail[i][j]<<" ";
            if(snail[i][j] == find){
                find_i = i;
                find_j = j;
            }
        }
        cout<<"\n";
    }
    cout<<find_i+1<<" "<<find_j+1<<"\n";
}
