#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int N, K;
    int cnt = 0;
    cin>>N>>K;
    int* numbers = new int[N+1];
    for(int i=0;i<N+1;i++){
        numbers[i] = 1;
    }
    bool flag = true;
    
    for(int i=2;i<=N;i++){
        if(flag){
            if(numbers[i] == 1){
                int j = i;
                while(j<N+1){
                    if(numbers[j] == 1){
                        numbers[j] = 0;
                        cnt++;
                    }
                    if(cnt == K) {
                        cout<<j<<"\n";
                        flag = false;
                        break;
                    }
                    j+=i;
                }
            }
        }
    }
}
