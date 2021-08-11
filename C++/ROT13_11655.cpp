#include <iostream>
#include <cctype>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    string s1;
    getline(cin, s1);
    for(int i=0;i<s1.length();i++){
        if(isalpha(s1[i])){
            if(isupper(s1[i])){
                s1[i] += 13;
                if(s1[i]>90){s1[i]-=26;}
            }
            else if(islower(s1[i])){
                if(s1[i]+13 <= 122){s1[i]+=13;}
                else{s1[i]-=13;}
            }
        }
    }
    cout<<s1<<"\n";
}


