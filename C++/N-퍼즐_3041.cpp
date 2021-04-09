#include <iostream>
#include <cctype>
#include <cstdlib> // int abs(int num)
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    char puzzle_sol[4][4] = {{'A','B','C','D'}, {'E','F','G','H'}, {'I','J','K','L'}, {'M','N','O','.'}};
    char puzzle[4][4];
    
    int distance, sum = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        cin>>puzzle[i][j];
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(isalpha(puzzle[i][j])){
                if(puzzle[i][j] != puzzle_sol[i][j]){
                    for(int a=0;a<4;a++){
                        for(int b=0;b<4;b++){
                            if(puzzle[i][j] == puzzle_sol[a][b]){
                                distance = abs(a-i) + abs(b-j);
                                sum += distance;
                                goto EXIT;
                            }
                        }
                    }
                }
            }
            EXIT: continue;
        }
    }
    cout<<sum<<"\n";
}
