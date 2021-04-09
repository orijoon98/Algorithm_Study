#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

string croatia[8] = {"c=","c-","d-","lj","nj","s=","z=","dz="};

int main(){
    string str;
    cin>>str;
    int cnt = 0;
    for(int i=0;i<str.length();i++){
        for(int j=0;j<7;j++){
            if(i+1 < str.length()){
                if(str.substr(i, 2) == croatia[j]){
                    cnt++;
                    i+=1;
                    break;
                }
            }
            if(i+2 < str.length()){
                if(str.substr(i, 3) == croatia[7]){
                    cnt++;
                    i+=2;
                    break;
                }
            }
            if(j == 6) cnt++;
        }
    }
    cout<<cnt<<"\n";
}
