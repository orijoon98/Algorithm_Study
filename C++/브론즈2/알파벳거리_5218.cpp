#include <iostream>
using namespace std;

int main(){
    char alpha[26];
    for(int i=0, a='A';i<26;i++){
        alpha[i] = a;
        a++;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string x, y;
        int x_num=0, y_num=0;
        cin>>x>>y;
        for(int j=0;j<x.length();j++){
            for(int k=0;k<26;k++){
                if(x[j]==alpha[k]){
                    x_num = k+1;
                    break;
                }
            }
            for(int k=0;k<26;k++){
                if(y[j]==alpha[k]){
                    y_num = k+1;
                    break;
                }
            }
            if(j == 0){
                cout<<"Distances: ";
            }
            if(y_num >= x_num){
                cout<<y_num-x_num<<' ';
            }
            else{
                cout<<(y_num+26)-x_num<<' ';
            }
            if(j==x.length()-1){
                cout<<endl;
            }
        }

    }
}
