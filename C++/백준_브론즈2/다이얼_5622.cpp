#include <iostream>
using namespace std;

int main(){
    string number;
    int sum = 0;
    cin>>number;
    for(int i=0;i<number.length();i++){
        if(number[i] == 'A' || number[i] == 'B' || number[i] == 'C'){
            sum+=3;
        }
        else if(number[i] == 'D' || number[i] == 'E' || number[i] == 'F'){
            sum+=4;
        }
        else if(number[i] == 'G' || number[i] == 'H' || number[i] == 'I'){
            sum+=5;
        }
        else if(number[i] == 'J' || number[i] == 'K' || number[i] == 'L'){
            sum+=6;
        }
        else if(number[i] == 'M' || number[i] == 'N' || number[i] == 'O'){
            sum+=7;
        }
        else if(number[i] == 'P' || number[i] == 'Q' || number[i] == 'R' || number[i] == 'S'){
            sum+=8;
        }
        else if(number[i] == 'T' || number[i] == 'U' || number[i] == 'V'){
            sum+=9;
        }
        else if(number[i] == 'W' || number[i] == 'X' || number[i] == 'Y' || number[i] == 'Z'){
            sum+=10;
        }
    }
    cout<<sum<<endl;

}
