#include <iostream>
using namespace std;

int main(){
    int hour, minute;
    int time;
    int minute_add;
    cin>>hour>>minute;
    cin>>time;
    minute+=time;
    if(minute>=60){
        minute_add = minute/60;
        minute-=60*minute_add;
        hour+=minute_add;
        if(hour>=24){
            hour-=24;
        }
    }
    cout<<hour<<' '<<minute<<endl;
}
