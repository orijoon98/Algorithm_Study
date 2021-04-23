#include <iostream>
#include <string>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int A, B, D;
    cin>>A>>B>>D;
    int* prime = new int[B+1];
    for(int i=2;i<=B;i++){
        prime[i] = i;
    }
    for(int i=2;i<=B;i++){
        if(prime[i] == 0) continue;
        for(int j=i+i;j<=B;j+=i){
            prime[j] = 0;
        }
    }
    int cnt = 0;
    for(int i=A;i<=B;i++){
        if(prime[i] != 0){
            string check = to_string(prime[i]);
            for(int j=0;j<check.length();j++){
                if(check[j] == D+48) {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<"\n";
}
