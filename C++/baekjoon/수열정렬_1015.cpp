#include <iostream>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int n;
    cin>>n;
    int* numbers = new int[n];
    int* sorted = new int[n];
    int* count = new int[n];
    for(int i=0;i<n;i++){
        count[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin>>numbers[i];
        sorted[i] = numbers[i];
    }
    sort(sorted, sorted+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(numbers[i] == sorted[j]){
                cout<<j+count[j]<<" ";
                count[j]++;
                break;
            }
        }
    }
}
