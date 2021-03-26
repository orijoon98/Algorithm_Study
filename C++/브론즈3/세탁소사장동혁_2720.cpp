#include <iostream>
using namespace std;

int main(){
    int N;
    int price;
    int c25=0,c10=0,c5=0,c1=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>price;
        c25=price/25;
        c10=(price%25)/10;
        c5=((price%25)%10)/5;
        c1=((price%25)%10)%5;
        cout<<c25<<' '<<c10<<' '<<c5<<' '<<c1<<endl;
    }
}

