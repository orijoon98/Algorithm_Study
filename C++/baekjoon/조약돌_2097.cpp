#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n, result;
    int i = 3;
    cin>>n;
    while(true){
        if(n<=i*i - i) break;
        i++;
    }
    if(n>(i-1)*(i-1)) result = 4 + 2 * ((i-3) * 2 + 1);
    else result = 4 + 2 * ((i-3) * 2);
    cout<<result<<"\n";
}
