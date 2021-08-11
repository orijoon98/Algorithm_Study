#include <iostream>
using namespace std;

int main(){
    int number;
    int cnt=0;
    cin>>number;
    int *students = new int[number];
    for(int i=0;i<number;i++){
        cin>>students[i];
    }
    for(int i=1;i<=number;i++){
        if(i!=students[i-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
