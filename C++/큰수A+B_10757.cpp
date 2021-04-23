#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){ 
    string a, b;
    string answer = "";
    cin>>a>>b;
    int i = a.length()-1, j = b.length()-1;
    int ten = 0, one = 0;
    while(true){
        int sum;
        if(i>=0 && j>=0) sum = a[i] - 48 + b[j] - 48;
        else if(i>=0 && j<0) sum = a[i] - 48;
        else if(i<0 && j>=0) sum = b[j] - 48;
        else{
            if(ten != 0) answer += to_string(ten);
            break;
        }
        one = ten + sum;
        if(one < 10){
            answer += to_string(one);
            ten = 0;
        }
        else{
            ten = one / 10;
            one = one % 10;
            answer += to_string(one);
        }
        i--;
        j--;
    }
    reverse(answer.begin(), answer.end());
    cout<<answer<<"\n";
}
