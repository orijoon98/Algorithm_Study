#include <iostream>
using namespace std;

int main(){
    int war;
    int a;
    cin>>war;
    int gandalf[6], sauron[7];
    int gan_p, sau_p;
    for(a=1;a<=war;a++){
        cin>>gandalf[0]>>gandalf[1]>>gandalf[2]>>gandalf[3]>>gandalf[4]>>gandalf[5];
        cin>>sauron[0]>>sauron[1]>>sauron[2]>>sauron[3]>>sauron[4]>>sauron[5]>>sauron[6];
        gan_p = gandalf[0]+gandalf[1]*2+gandalf[2]*3+gandalf[3]*3+gandalf[4]*4+gandalf[5]*10;
        sau_p = sauron[0]+sauron[1]*2+sauron[2]*2+sauron[3]*2+sauron[4]*3+sauron[5]*5+sauron[6]*10;
        cout<<"Battle "<<a<<": ";
        if(gan_p > sau_p){
            cout<<"Good triumphs over Evil"<<endl;
        }
        else if(sau_p > gan_p){
            cout<<"Evil eradicates all trace of Good"<<endl;
        }
        else{
            cout<<"No victor on this battle field"<<endl;
        }
    }
}
