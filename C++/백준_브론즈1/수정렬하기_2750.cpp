#include <iostream>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void selectionSort(int arr[], int size){//선택정렬법
    int minIndex, min;
    for(int i=0;i<size-1;i++){
        minIndex = i;
        min = arr[minIndex];
        for(int j=i+1;j<size;j++){
            if(arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
            if(j==size-1)
                swap(arr[i], arr[minIndex]);
        }
    }
}

int main(){
    FAST;
    int n;
    cin>>n;
    int *numbers = new int[n];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    selectionSort(numbers, n);
    for(int i=0;i<n;i++){
        cout<<numbers[i]<<"\n";
    }
}
