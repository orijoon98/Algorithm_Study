#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int strike(int a, int b){
    int cnt = 0;
    int a_100, b_100, a_10, b_10, a_1, b_1;
    a_100 = a/100;
    b_100 = b/100;
    a_10 = a%100/10;
    b_10 = b%100/10;
    a_1 = a%10;
    b_1 = b%10;
    if(a_100 == b_100) cnt++;
    if(a_10 == b_10) cnt++;
    if(a_1 == b_1) cnt++;
    return cnt;
}

int ball(int a, int b){
    int cnt = 0;
    int a_100, b_100, a_10, b_10, a_1, b_1;
    a_100 = a/100;
    b_100 = b/100;
    a_10 = a%100/10;
    b_10 = b%100/10;
    a_1 = a%10;
    b_1 = b%10;
    if(a_100 == b_10 || a_100 == b_1) cnt++;
    if(a_10 == b_100 || a_10 == b_1) cnt++;
    if(a_1 == b_100 || a_1 == b_10) cnt++;
    return cnt++;
}

int main(){
    int n;
    int cnt = 0;
    cin>>n;
    int* baseball = new int[3*n];
    for(int i=0;i<3*n-2;i+=3){
        cin>>baseball[i]>>baseball[i+1]>>baseball[i+2];
    }
    for(int a=1;a<10;a++){
        for(int b=1;b<10;b++){
            for(int c=1;c<10;c++){
                if(a!=b && a!=c && b!=c){
                    int guess = 100*a + 10*b + c;
                    for(int i=0;i<3*n-2;i+=3){
                        if(strike(guess, baseball[i]) == baseball[i+1] && ball(guess, baseball[i]) == baseball[i+2]) {
                            if(i == 3*n - 3) cnt++;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<"\n";
}
