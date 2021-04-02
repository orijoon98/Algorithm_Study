#include <iostream>
using namespace std;

int main(){
    long G=0, T=0, A=0, D=0, X, Y;

    while(true){
        cin>>G>>T>>A>>D;
        long binary = 1, tournament_teams;
        tournament_teams = G * A + D;
        if((G==-1)&&(A==-1)&&(T==-1)&&(D==-1)) break;
        if(tournament_teams <= 1) binary = 1;
        else{
            for(int i=0;i<62;i++){
                binary = (binary << 1);
                if(binary >= tournament_teams) break;
            }
        }
        Y = binary - tournament_teams;
        X = G * (T-1) * T / 2 + binary - 1;
        cout<<G<<"*"<<A<<"/"<<T<<"+"<<D<<"="<<X<<"+"<<Y<<"\n";
    }
}
