#include <iostream>
using namespace std;

int main(){
    int n=1;
    while(true){
        cin>>n;
        if(n==0){break;}
        int choco, ch;
        cin>>choco;
        if(n==1){
            cout<<choco<<" $"<<endl;
        }
        else{
            cout<<choco<<' ';
            for(int a=1;a<n;a++){
                ch = choco;
                cin>>choco;
                if(ch != choco){
                    cout<<choco<<' ';
                }
                if(a==n-1){
                    cout<<'$'<<endl;
                }
            }
        }
    }
}
