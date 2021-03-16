#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int *shops = new int[n];
        int min=99, max=0;
        for(int j=0;j<n;j++){
            cin>>shops[j];
            if(shops[j]<min){
                min = shops[j];
            }
            if(shops[j]>max){
                max = shops[j];
            }
        }
        cout<<(max-min)*2<<endl;
    }
    
}
