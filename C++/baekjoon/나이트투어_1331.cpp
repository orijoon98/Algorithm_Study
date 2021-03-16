#include <iostream>
#include <cmath>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int chess[6][6]{}; //0으로 초기화
    string move[36];
    string start;
    for(int i=0;i<36;i++){
        cin>>move[i];
    }
    start = move[0];
    for(int i=0;i<36;i++){
        if(move[i][0] >= 'A' && move[i][0] <= 'F'){
            if(move[i][1] >= '1' && move[i][1] <= '6'){
                if(i<35){
                    if((abs(move[i][0] - move[i+1][0]) == 2 && abs(move[i][1] - move[i+1][1]) == 1) || (abs(move[i][0] - move[i+1][0]) == 1 && abs(move[i][1] - move[i+1][1]) == 2)){
                        if(chess[(int)move[i][0] - 65][(int)move[i][1] - 49] == 0){
                            chess[(int)move[i][0] - 65][(int)move[i][1] - 49] = 1;
                        }
                        else{
                            cout<<"Invalid"<<"\n";
                            break;
                        }
                    }
                    else{
                        cout<<"Invalid"<<"\n";
                        break;
                    }
                }
                else if(i == 35){
                    if(chess[(int)move[i][0] - 65][(int)move[i][1] - 49] == 0){
                        chess[(int)move[i][0] - 65][(int)move[i][1] - 49] = 1;
                        if((abs(move[i][0] - start[0]) == 2 && abs(move[i][1] - start[1]) == 1) || (abs(move[i][0] - start[0]) == 1 && abs(move[i][1] - start[1]) == 2)){
                            cout<<"Valid"<<"\n";
                        }
                        else{
                            cout<<"Invalid"<<"\n";
                            break;
                        }
                        
                    }
                    else{
                        cout<<"Invalid"<<"\n";
                        break;
                    }
                }
            }
            else{
                cout<<"Invalid"<<"\n";
                break;
            }
        }
        else{
            cout<<"Invalid"<<"\n";
            break;
        }
    }
}
