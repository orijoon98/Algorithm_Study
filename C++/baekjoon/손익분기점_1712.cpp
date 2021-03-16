#include <iostream>
using namespace std;

int main(){
    int ing,ch,price;
    int cnt;

    cin>>ing>>ch>>price;
    if(ch>=price){
        cout<<-1<<endl;
    }
    else{
        cnt = ing/(price-ch)+1;
        cout<<cnt<<endl;
    }
}
