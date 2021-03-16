#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

long long memo[80] = {0, 1, 2};

long long fibo(long long n){
    if(memo[n] != 0) return memo[n];
    else {
        
        long long a;
        a = fibo(n-1) + fibo(n-2);
        memo[n] = a;
        return a;
    }
}

int main(){
    FAST;
    long long n;
    cin>>n;
    long long perimeter = 4;
    for(long long i=1;i<n;i++){
        perimeter += (fibo(i) * 2);
    }
    cout<<perimeter<<"\n";
}
