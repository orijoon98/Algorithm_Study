#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N, M, ans;
bool unable_num[10]; // 고장난 번호
int initial = 100;
int up, down;
int cnt = 0;
int button_num;
int closest;

bool able(int number){
    closest = number;
    button_num = 0;
    if(number == 0){
        button_num = 1;
        if(unable_num[0]) return false;
        else return true;
    }
    while(number != 0){
        int a = number % 10;
        if(unable_num[a]) return false;
        number /= 10;
        button_num++;
    }
    return true;
}

void search_close(){
    bool flag = false;
    while(true){
        if(able(down)) flag = true;
        if(flag) break;
        if(able(up)) flag = true;
        if(flag) break;
        up++;
        if(down - 1 >= 0) down--;
        cnt++;

    }
    return;
}

bool initCheck(){
    for(int i=0;i<10;i++){
        if(unable_num[i] == false) return true;
    }
    return false;
}

void input(){
    cin>>N;
    cin>>M;
    while(M--){
        int num;
        cin>>num;
        unable_num[num] = true;
    }
    up = N;
    down = N;
}

int main(){
    FAST;
    input();
    if(N == 100){
        cout<<0;
        return 0;
    }
    if(!initCheck()) cout<<abs(N-100);
    else{
        search_close();
        ans = min(button_num + cnt, abs(N - 100));
//        cout<<closest<<endl;
        cout<<ans;
    }
}
