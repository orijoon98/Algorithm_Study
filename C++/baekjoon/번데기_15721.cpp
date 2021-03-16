#include <iostream>
using namespace std;

int main(){
    int A, T, G;
    cin>>A>>T>>G;
    int sentence=0, sentence_cnt=0, cnt=6;
    while(sentence<2*T){
        cnt += 2;
        sentence += cnt;
        sentence_cnt += 1;
    }
    if(G == 0){
        if(T>= sentence/2 - (sentence_cnt)){
            sentence -= ((cnt - 4)/2) + (sentence/2 - T);
        }
        else{
            sentence = 2*T - 1;
        }
    }
    else{
        if(T>= sentence/2 - (sentence_cnt)){
            sentence -= (sentence/2 - T);
        }
        else{
            sentence = 2*T;
        }
    }
    while(sentence > A){
        sentence -= A;
    }
    cout<<sentence - 1<<"\n";
}
