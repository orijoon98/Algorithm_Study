#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int numbers[10] = {0,};
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++) numbers[n[i]-48]++;
    int max = 0, state = 0;
    for(int i=0;i<10;i++){
        if(numbers[i] > max){
            max = numbers[i];
            state = i;
        }
    }
    if(state == 6 || state == 9) max = (numbers[6]+numbers[9]+1) / 2;
    cout<<max<<"\n";
}
