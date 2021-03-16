#include <iostream>
using namespace std;

int main(){
    int N;
    int star1=1;
    int a=0,b=0,c=0,d=0,e=0;
    cin>>N;
    int star2=N-1,star3=N-1;


    for(a=0;a<N;a++){
        for(b=0;b<star1;b++){
            cout<<'*';
        }
        star1++;
        for(c=0;c<N-b;c++){
            cout<<' ';
        }
        for(d=0;d<star2;d++){
            cout<<' ';
        }
        for(e=0;e<N-d;e++){
            cout<<'*';
        }
        star2--;
        cout<<endl;
    }
    for(a=0;a<N-1;a++){
        for(b=0;b<star3;b++){
            cout<<'*';
        }
        for(c=0;c<=a;c++){
            cout<<' ';
        }
        for(d=0;d<=a;d++){
            cout<<' ';
        }
        for(e=0;e<star3;e++){
            cout<<'*';
        }
        star3--;
        cout<<endl;
    }
}
