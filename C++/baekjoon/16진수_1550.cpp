#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    string number;
    int answer=0, j=0;
    long i;

    cin>>number;
    for(i=number.length()-1;i>=0;i--){
        switch(number[j]){
            case '0':
                answer += pow(16, i)*0;
                j++;
                break;
            case '1':
                answer += pow(16, i)*1;
                j++;
                break;
            case '2':
                answer += pow(16, i)*2;
                j++;
                break;
            case '3':
                answer += pow(16, i)*3;
                j++;
                break;
            case '4':
                answer += pow(16, i)*4;
                j++;
                break;
            case '5':
                answer += pow(16, i)*5;
                j++;
                break;
            case '6':
                answer += pow(16, i)*6;
                j++;
                break;
            case '7':
                answer += pow(16, i)*7;
                j++;
                break;
            case '8':
                answer += pow(16, i)*8;
                j++;
                break;
            case '9':
                answer += pow(16, i)*9;
                j++;
                break;
            case 'A':
                answer += pow(16, i)*10;
                j++;
                break;
            case 'B':
                answer += pow(16, i)*11;
                j++;
                break;
            case 'C':
                answer += pow(16, i)*12;
                j++;
                break;
            case 'D':
                answer += pow(16, i)*13;
                j++;
                break;
            case 'E':
                answer += pow(16, i)*14;
                j++;
                break;
            case 'F':
                answer += pow(16, i)*15;
                j++;
                break;
        }
    }
    cout<<answer<<endl;
}

