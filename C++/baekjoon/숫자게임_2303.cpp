#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int n;
    cin>>n;
    int** numbers = new int*[n];
    for(int i=0;i<n;i++){
        numbers[i] = new int[5];
        for(int j=0;j<5;j++){
            cin>>numbers[i][j];
        }
    }
    int* max = new int[n];
    for(int x=0;x<n;x++){
        int max_num = 0;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                for(int k=j+1;k<5;k++){
                    int sum;
                    sum = (numbers[x][i] + numbers[x][j] + numbers[x][k]) % 10;
                    if(sum>max_num) max_num = sum;
                    max[x] = max_num;
                }
            }
        }
    }
    int MAX = 0;
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(max[i] >= MAX) {
            MAX = max[i];
            answer = i+1;
        }
    }
    cout<<answer<<"\n";
}
