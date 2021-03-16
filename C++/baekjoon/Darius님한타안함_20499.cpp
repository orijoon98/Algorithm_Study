#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    char kd[10];
    int KD[2];
    int A;
    for(int i=0;i<2;i++){
        cin.getline(kd,10,'/');
        KD[i] = atoi(kd);
    }
    cin>>A;
    if(((KD[0]+A)<KD[1])||(KD[1]==0)){
        cout<<"hasu"<<endl;
    }
    else{
        cout<<"gosu"<<endl;
    }
}
