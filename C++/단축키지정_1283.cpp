#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string options[31];//n번째 옵션

int main(){
    FAST;
    int n;
    cin>>n;
    cin.ignore();
    char shortcuts[31];//n번째 옵션 단축키
    fill(shortcuts, shortcuts+31, '0');
    for(int i=1;i<=n;i++){
        getline(cin, options[i]);
        bool flag = true;// 단어 구별하기위함
        if(options[i] != ""){
            for(int j=0;j<options[i].length();j++){
                if(isalpha(options[i][j])){
                    if(flag){
                        flag = false;
                        for(int k=1;k<=i;k++){
                            if(tolower(options[i][j]) == shortcuts[k]){
                                break;
                            }
                            if(shortcuts[k] == '0' && k == i){
                                shortcuts[i] = tolower(options[i][j]);
                                break;
                            }
                        }
                    }
                }
                if(options[i][j] == ' ') flag = true;
            }
            if(shortcuts[i] == '0'){// 단어별 첫글자로 단축키 못정했을때
                for(int j=0;j<options[i].length();j++){
                    if(isalpha(options[i][j])){
                        for(int k=1;k<=i;k++){
                            if(tolower(options[i][j]) == shortcuts[k]){
                                break;
                            }
                            if(shortcuts[k] == '0' && k == i){
                                shortcuts[i] = tolower(options[i][j]);
                                break;
                            }
                        }
                    }
                    if(shortcuts[i] != '0') break;
                }
            }
        }
        if(shortcuts[i] == '0') cout<<options[i]<<'\n';
        else{
            flag = true;
            bool flag2 = true;
            for(int j=0;j<options[i].length();j++){
                if(flag){
                    flag = false;
                    if(tolower(options[i][j]) == shortcuts[i]){
                        string str="[";
                        str.push_back(options[i][j]);
                        str.push_back(']');
                        options[i].replace(j, 1, str);
                        cout<<options[i]<<'\n';
                        flag2 = false;
                        break;
                    }
                }
                if(options[i][j] == ' ') flag = true;
            }
            if(flag2){
                for(int j=0;j<options[i].length();j++){
                    if(tolower(options[i][j]) == shortcuts[i]){
                        string str="[";
                        str.push_back(options[i][j]);
                        str.push_back(']');
                        options[i].replace(j, 1, str);
                        cout<<options[i]<<'\n';
                        break;
                    }
                }
            }
        }
    }
}
