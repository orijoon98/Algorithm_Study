#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int K, score;

class Wheel{
public:
    int state[8];
    int top = 0;
    int left = 6, right = 2;
    void rotate_wheel(bool dir){
        if(dir == 1){
            if(top == 0) top = 7;
            else top--;
            if(left == 0) left = 7;
            else left--;
            if(right == 0) right = 7;
            else right--;
        }
        if(dir != 1){
            if(top == 7) top = 0;
            else top++;
            if(left == 7) left = 0;
            else left++;
            if(right == 7) right = 0;
            else right++;
        }
    }
};

Wheel wheels[4];

int main(){
    FAST;
    for(int i=0;i<4;i++){
        int num;
        cin>>num;
        Wheel wheel;
        wheels[i] = wheel;
        for(int j=7;j>=0;j--){
            wheels[i].state[j] = num % 10;
            num /= 10;
        }
    }
    cin>>K;
    while(K--){
        int wheel_num, boolean;
        bool dir;
        cin>>wheel_num>>boolean;
        if(boolean == 1) dir = true;
        else dir = false;
        int cur = wheel_num - 1; // 돌리는 톱니바퀴
        bool rotate_left = false, rotate_right = false;
        bool rotate_left_2 = false, rotate_right_2 = false;
        bool rotate_left_3 = false, rotate_right_3 = false;
        if(cur-1>=0 && wheels[cur-1].state[wheels[cur-1].right] != wheels[cur].state[wheels[cur].left]) rotate_left = true;
        if(rotate_left){
            if(cur-2>=0 && wheels[cur-2].state[wheels[cur-2].right] != wheels[cur-1].state[wheels[cur-1].left]){
                rotate_left_2 = true;
            }
        }
        if(rotate_left && rotate_left_2){
            if(cur-3>=0 && wheels[cur-3].state[wheels[cur-3].right] != wheels[cur-2].state[wheels[cur-2].left]){
                rotate_left_3 = true;
            }
        }
        if(cur+1<4 && wheels[cur+1].state[wheels[cur+1].left] != wheels[cur].state[wheels[cur].right]) rotate_right = true;
        if(rotate_right){
            if(cur+2<4 && wheels[cur+2].state[wheels[cur+2].left] != wheels[cur+1].state[wheels[cur+1].right]){
                rotate_right_2 = true;
            }
        }
        if(rotate_right && rotate_right_2){
            if(cur+3<4 && wheels[cur+3].state[wheels[cur+3].left] != wheels[cur+2].state[wheels[cur+2].right]){
                rotate_right_3 = true;
            }
        }
        wheels[cur].rotate_wheel(dir);
//        cout<<cur<<"회전"<<endl;
        if(rotate_left){
            wheels[cur-1].rotate_wheel(!dir);
//            cout<<cur-1<<"회전"<<endl;
            if(rotate_left_2){
                wheels[cur-2].rotate_wheel(dir); // 반대방향의 반대방향으로 회전시킨다
//                cout<<cur-2<<"회전"<<endl;
            }
            if(rotate_left_3){
                wheels[cur-3].rotate_wheel(!dir);
//                cout<<cur-3<<"회전"<<endl;
            }
        }
        if(rotate_right){ // 오른쪽이 존재한다면
            wheels[cur+1].rotate_wheel(!dir);
//            cout<<cur+1<<"회전"<<endl;
            if(rotate_right_2){
                wheels[cur+2].rotate_wheel(dir);
//                cout<<cur+2<<"회전"<<endl;
            }
            if(rotate_right_3){
                wheels[cur+3].rotate_wheel(!dir);
//                cout<<cur+3<<"회전"<<endl;
            }
        }
    }
    for(int i=0;i<4;i++){
        if(wheels[i].state[wheels[i].top] == 1){
            switch (i) {
                case 0:
                    score += 1;
                    break;
                case 1:
                    score += 2;
                    break;
                case 2:
                    score += 4;
                    break;
                default: // case 3:
                    score += 8;
                    break;
            }
        }
    }
    cout<<score;
}
