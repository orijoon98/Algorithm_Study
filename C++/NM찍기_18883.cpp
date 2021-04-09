#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=1+i*m;j<=(i+1)*m;j++){
            if(j==(i+1)*m){
                cout<<j<<endl;
            }
            else{
            cout<<j<<' ';
            }
        }
    }

}
