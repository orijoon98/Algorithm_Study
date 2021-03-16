#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int L, C;
char alpha[20];
bool used[20];
vector<char> passwd;
int vowel = 0, consonant = 0;

void input(){
    cin>>L>>C;
    for(int i=0;i<C;i++){
        cin>>alpha[i];
    }
    sort(alpha, alpha + C);
}

void func(int n, int index){
    if(n == L){
        for(int i=0;i<L;i++){
            if(passwd[i] == 'a' || passwd[i] == 'e' || passwd[i] == 'i' || passwd[i] == 'o' || passwd[i] == 'u'){
                vowel++;
            }
            else consonant++;
        }
        if(vowel < 1 || consonant < 2){
            vowel = 0;
            consonant = 0;
            return;
        }
        for(int i=0;i<L;i++){
            cout<<passwd[i];
        }
        cout<<'\n';
        vowel = 0;
        consonant = 0;
        return;
    }
    for(int i=index;i<C;i++){
        if(used[i]) continue;
        used[i] = true;
        passwd.push_back(alpha[i]);
        func(n + 1, i);
        used[i] = false;
        passwd.pop_back();
    }
}

int main(){
    FAST;
    input();
    func(0, 0);
}
