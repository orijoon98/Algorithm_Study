#include <iostream>
using namespace std;

int main(){
    string word;
    cin>>word;
    int i=0;
    for(int j=i;j<i+10;j++){
        if(word[j]=='\0'){
            cout<<endl;
            break;
        }
        else{
            cout<<word[j];
            if(j==i+9){
                cout<<endl;
                i+=10;
            }
        }
    }
}
