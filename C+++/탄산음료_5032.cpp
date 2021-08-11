#include <iostream>
using namespace std;

int main(){
    int e, f, c;
    int coke;
    int cnt;
    cin>>e>>f>>c;
    coke = (e+f)/c;
    cnt = coke + (e+f)%c;
    while(cnt/c>=1){
        int a = cnt/c;
        coke+= a;
        cnt = a + cnt%c;
    }
    cout<<coke<<endl;
}
