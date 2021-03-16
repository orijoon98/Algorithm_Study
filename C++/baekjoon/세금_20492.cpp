#include <iostream>
using namespace std;

int main(){
    int prize;
    int answer1, answer2;
    cin>>prize;
    answer1 = prize/100*78;
    answer2 = prize/100*80 + prize/100*20/100*78;
    cout<<answer1<<' '<<answer2<<endl;
}
