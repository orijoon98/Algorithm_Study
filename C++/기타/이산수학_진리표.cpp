#include <iostream>
#include <deque>
#include <cmath>
#include <cctype>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool nHasChar(char* arr, char a){
    int i=0;
    while(arr[i]!='N'){
        if(arr[i] == a){
            return false;
        }
        i++;
    }
    return true;
}

int operate(int a, char o, int b){
    switch (o) {
        case 'a':
            if(a == 1 && b == 1){return 1;}
            else{return 0;}
        case 'o':
            if(a == 0 && b == 0){return 0;}
            else{return 1;}
        default://i
            if(a == 1 && b == 0){return 0;}
            else{return 1;}
            break;
    }
}

int no(int a){
    if(a==1){return 0;}
    else{return 1;}
}

int main(){
    FAST;
    int var_num, oper_num, total;
    cin>>var_num>>oper_num>>total;
    int **values = new int*[1<<var_num];
    if(var_num == 2){
        for (int i = 0; i < (1 << var_num); i++){
            values[i] = new int[var_num];
        }
        values[0][0] = 1;
        values[0][1] = 1;
        values[1][0] = 1;
        values[1][1] = 0;
        values[2][0] = 0;
        values[2][1] = 1;
        values[3][0] = 0;
        values[3][1] = 0;
    }
    else{
        for (int i = 0; i < (1 << var_num); i++) { // 진리값 2차원 배열
            values[i] = new int[var_num];
            if(var_num == 3){
                for (int j = var_num-1; j >= 0; j--) {
                     if (i & (1 << j)) { values[i][2-j] = 0; }
                     else { values[i][2-j] = 1; }
                }
            }
            else{
                for (int j = var_num-1; j >= 0; j--) {
                    values[i][j] = 1-i;
                }
            }
        }
    }
    cin.ignore();
    char *vars = new char[total*2];
    cin.getline(vars, total*2);
    char *varOrder = new char[var_num+1];
    varOrder[var_num] = 'N';
    int cnt = 0;
    for(int i = 0; i < total*2; i++ ){
        if(isupper(vars[i])){
            if(nHasChar(varOrder, vars[i])){
                varOrder[cnt] = vars[i];
                cnt++;
            }
        }
    }
    for(int i=0;i<var_num;i++){ // P, Q, R 순으로 배열
        char space;
        if(var_num == 3){
            if(i==var_num-1){
                if(varOrder[1]<varOrder[0]){
                    space = varOrder[1];
                    varOrder[1] = varOrder[0];
                    varOrder[0] = space;
                }
            }
            else{
                if(varOrder[i]>varOrder[i+1]){
                    space = varOrder[i+1];
                    varOrder[i+1] = varOrder[i];
                    varOrder[i] = space;
                }
            }
        }
        
        else if(var_num == 2){
            if(varOrder[0]>varOrder[1]){
                space = varOrder[1];
                varOrder[1] = varOrder[0];
                varOrder[0] = space;
            }
        }
    }

    for(int i = 0; i < var_num; i++){
        cout<<varOrder[i]<<' ';
    }
    cout<<"RESULT\n\n";
    
    
    //진리표 작성
    //------------------------------------------------------------
    for (int i = 0; i < (1 << var_num); i++){
        int result = 1;
        
        for(int j = 0; j< var_num; j++){
            if(values[i][j] == 1){cout<<"T ";}
            else{cout<<"F ";}
        }
        deque<char> var, oper;
        deque<int> operated_list;
        for(int j=0;j<total*2;j++){
            if(isupper(vars[j])){
                var.push_back(vars[j]);
            }
            else if(islower(vars[j])){
                
                oper.push_back(vars[j]);
                if(vars[j]=='n'){
                    continue;
                }
                
            }
            else{
                continue;
            }
            if(var.size()>=1 && oper.size()>=1){
                char left, right, op;
                int left_v=1, right_v=1, operated;
                
                
                op = oper.back();
                if(op != 'n'){
                    if(var.size()>=2){
                        oper.pop_back();
                        if(operated_list.size() == 0){
                            right = var.back();
                            var.pop_back();
                            left = var.back();
                            var.pop_back();
                            
                            for(int k = 0; k < var_num; k++){
                                if(left == varOrder[k]){
                                    left_v = values[i][k];
                                }
                            }
                            for(int k = 0; k < var_num; k++){
                                if(right == varOrder[k]){
                                    right_v = values[i][k];
                                }
                            }
                            operated = operate(left_v, op, right_v);
                            operated_list.push_front(operated);
                            var.push_front((char)operated);
                            result = operated;
                        }
                        else{
                            left_v = operated_list.back();
                            operated_list.pop_back();
                            right = var.back();
                            var.pop_back();
                            for(int k = 0; k < var_num; k++){
                                if(right == varOrder[k]){
                                    right_v = values[i][k];
                                }
                            }
                            operated = operate(left_v, op, right_v);
                            operated_list.push_front(operated);
                            result = operated;
                            
                        }
                    }
                }
                   
                else{
                    while(oper.size()!=0){
                        if(operated_list.size()>=2){
                            op = oper.back();
                            oper.pop_back();
                            left_v = operated_list.back();
                            operated_list.pop_back();
                            right_v = operated_list.back();
                            operated_list.pop_back();
                            operated = operate(left_v, op, right_v);
                            operated_list.push_front(operated);
                            result = operated;
                        }
                        else if(oper.size()==1 && var.size()==1){
                            op = oper.back();
                            oper.pop_back();
                            left = var.back();
                            for(int k = 0; k < var_num; k++){
                                if(left == varOrder[k]){
                                    left_v = values[i][k];
                                }
                            }
                            var.pop_back();
                            right_v = operated_list.back();
                            operated_list.pop_back();
                            operated = operate(left_v, op, right_v);
                            operated_list.push_front(operated);
                            result = operated;
                        }
                        else{
                            oper.pop_back();
                            right = var.back();
                            var.pop_back();
                            for(int k = 0; k < var_num; k++){
                                if(right == varOrder[k]){
                                    right_v = values[i][k];
                                }
                            }
                            operated = no(right_v);
                            operated_list.push_front(operated);
                            result = operated;
                        }
                    }
                }
            }
        }
        if(result == 1){cout<<"T\n\n";}
        else{cout<<"F\n\n";}
        

        

    }
}
