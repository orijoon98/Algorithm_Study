#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll numbers[1023];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin>>N;
    for(int i=0;i<10;i++){
        numbers[i] = i;
    }
    int count = 10;
    int index = 0;
    while(true){
        for(int i=0;i<=9;i++){
            if(numbers[index] % 10 > i){
                numbers[count++] = numbers[index] * 10 + i;
                if(count == 1023) break;
            }
        }
        if(count == 1023) break;
        index++;
    }
    sort(numbers, numbers+1023);
    if(N >= 1023){
        cout<<-1<<endl;
        return 0;
    }
    cout<<numbers[N]<<endl;
}
