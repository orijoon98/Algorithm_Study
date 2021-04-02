#include <iostream>
#include <cmath>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int A, B, V;
    int day = 0;
    cin>>A>>B>>V;
    if((V - A) % (A - B) == 0){
        day = (V - A) / (A - B);
        cout<<day+1<<"\n";
    }
    else{
        day = (V - A) / (A - B);
        cout<<day+2<<"\n";
    }
}
