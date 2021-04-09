//선택정렬 시간복잡도 O(n^2), 삽입정렬 시간복잡도 O(n^2), 버블정렬 시간복잡도 O(n^2), 합병정렬 시간복잡도 O(NlgN), 퀵정렬 시간복잡도 O(NlgN)

//#include <iostream> // 합병정렬 메모리초과
//using namespace std;
//#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

//void merge(int* arr, int left, int right, int size) {
//
//    int L, R, k, a;
//    int mid = (left + right) / 2;
//    L = left;
//    R = mid + 1;
//    k = left;
//    int* tmp = new int[size];
//
//    while (L <= mid && R <= right)
//        tmp[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
//
//    if (L>mid)
//        for (a = R; a <= right; a++)
//            tmp[k++] = arr[a];
//    else
//        for (a = L; a <= mid; a++)
//            tmp[k++] = arr[a];
//
//    for (a = left; a <= right; a++)
//        arr[a] = tmp[a];
//
//}
//
//
//void mergeSort(int* arr, int left, int right, int size) {
//
//    if (left == right) return;
//    int mid;
//    mid = (left + right) / 2;
//    mergeSort(arr, left, mid, size);
//    mergeSort(arr, mid + 1, right, size);
//    merge(arr, left, right, size);
//
//}
//
//int main(){
//    int n;
//    cin>>n;
//    int* numbers = new int[n];
//    for(int i=0;i<n;i++){
//        cin>>numbers[i];
//    }
//    mergeSort(numbers, 0, n-1, n);
//    for(int i=0;i<n;i++){
//        cout<<numbers[i]<<"\n";
//    }
//}

//#include <iostream> // 퀵 정렬 메모리초과
//using namespace std;
//#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//
//void swap(int *a, int *b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//void quick_sort(int* list, int left, int right)
//{
//    if (left >= right)
//        return;
//    int pivot = left;
//    int start = left + 1;
//    int end = right;
//    while (start<=end)
//    {
//        while (list[pivot] >= list[start] && start <= right)
//            start++;
//        while (list[pivot] <= list[end] && end > left)
//            end--;
//        if (start > end)
//        {
//            swap(list[pivot], list[end]);
//        }
//        else
//            swap(list[start], list[end]);
//    }
//    quick_sort(list, left, end - 1);
//    quick_sort(list, end + 1, right);
//
//}
//
//int main(){
//    FAST;
//    int n;
//    cin>>n;
//    int* numbers = new int[n];
//    for(int i=0;i<n;i++){
//        cin>>numbers[i];
//    }
//    quick_sort(numbers, 0, n-1);
//
//    for(int i=0;i<n;i++){
//        cout<<numbers[i]<<"\n";
//    }
//}

#include <iostream> // 숫자의 범위가 정해져 있을 때 계수정렬(Counting Sort)
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n;
    cin>>n;
    int numbers[10000] = {0,};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        numbers[a-1]++;
    }
    for(int i=0;i<10000;i++){
        if(numbers[i]!=0){
            for(int j=0;j<numbers[i];j++){
                cout<<i+1<<"\n";
            }
        }
    }
}
