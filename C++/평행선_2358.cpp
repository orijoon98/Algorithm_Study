//#include <iostream>
//using namespace std;
//#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//
//int main(){
//    FAST;
//    int n, cnt = 0;
//    cin>>n;
//    int **dots = new int *[n];
//    for(int i=0;i<n;i++){
//        dots[i] = new int[2];
//        cin>>dots[i][0]>>dots[i][1];
//
//    }
//    for(int i=0;i<n-1;i++){
//        for(int j=1;j<n-i;j++){
//            if(dots[i][0] == dots[i+j][0]) cnt++;
//        }
//        for(int j=1;j<n-i;j++){
//            if(dots[i][1] == dots[i+j][1]) cnt++;
//        }
//    }
//    cout<<cnt<<"\n";
//
//}

//#include <iostream> // 중복 여부에 따른 이진탐색 적용
//#include <algorithm>
//using namespace std;
//#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//
//int search_start(int *arr, int length, int target, int from){
//    int start = from;
//    int end = length - 1;
//    int mid = 0;
//    while(start <= end){
//        mid = (start + end) / 2;
//        if(arr[mid] < target)
//            start = mid + 1;
//        else {
//            end = mid - 1;
//        }
//    }
//    return start;
//}
//
//int search_end(int *arr, int length, int target, int from){
//    int start = from;
//    int end = length - 1;
//    int mid = 0;
//    while(start <= end){
//        mid = (start + end) / 2;
//        if(arr[mid] <= target)
//            start = mid + 1;
//        else
//            end = mid - 1;
//    }
//    return end;
//}
//
//int main(){
//    FAST;
//    int n, cnt = 0;
//    cin>>n;
//    int* x = new int[n];
//    int* y = new int[n];
//    for(int i=0;i<n;i++){
//        cin>>x[i];
//        cin>>y[i];
//    }
//    sort(x, x+n);
//    sort(y, y+n);
//    for(int i=0;i<n;i++){
//        int a, b;
//        a = search_start(x, n, x[i], i);
//        b = search_end(x, n, x[i], i);
//        cnt += b-a;
//        a = search_start(y, n, y[i], i);
//        b = search_end(y, n, y[i], i);
//        cnt += b-a;
//    }
//    cout<<cnt<<"\n";
//}

//#include <iostream> // O(nlogn) 100ms
//#include <algorithm>
//#include <set>
//using namespace std;
//#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//
//int search_start(int *arr, int length, int target){
//    int start = 0;
//    int end = length - 1;
//    int mid = 0;
//    while(start <= end){
//        mid = (start + end) / 2;
//        if(arr[mid] < target)
//            start = mid + 1;
//        else {
//            end = mid - 1;
//        }
//    }
//    return start;
//}
//
//int search_end(int *arr, int length, int target){
//    int start = 0;
//    int end = length - 1;
//    int mid = 0;
//    while(start <= end){
//        mid = (start + end) / 2;
//        if(arr[mid] <= target)
//            start = mid + 1;
//        else
//            end = mid - 1;
//    }
//    return end;
//}
//
//int main(){
//    FAST;
//    int n;
//    int cnt=0;
//    set<int> a, b;
//    cin>>n;
//    int* x = new int[n];
//    int* y = new int[n];
//    for(int i=0;i<n;i++){
//        cin>>x[i];
//        cin>>y[i];
//        a.insert(x[i]);
//        b.insert(y[i]);
//    }
//    sort(x, x+n);
//    sort(y, y+n);
//    for(auto it = a.begin();it!=a.end();it++){
//        int i, j;
//        i = search_start(x, n, *it);
//        j = search_end(x, n, *it);
//        if(i!=j) cnt++;
//    }
//    for(auto it = b.begin();it!=b.end();it++){
//        int i, j;
//        i = search_start(y, n, *it);
//        j = search_end(y, n, *it);
//        if(i!=j) cnt++;
//    }
//    cout<<cnt<<"\n";
//}

#include <iostream> // O(n) 36ms
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int a, b;
    int n, result=0;
    cin>>n;
    vector <int> pos_x;
    vector <int> pos_y;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        pos_x.push_back(a);
        pos_y.push_back(b);
    }
    sort(pos_x.begin(), pos_x.end());
    sort(pos_y.begin(), pos_y.end());
    
    bool flag_x = true, flag_y = true;
    for(int i=0; i<n-1; i++)
    {
        if(pos_x[i]==pos_x[i+1])
        {
            if(flag_x){
                result++;
                flag_x = false;
            }
        }
        else
            flag_x = true;
        if(pos_y[i]==pos_y[i+1])
        {
            if(flag_y){
                result++;
                flag_y = false;
            }
        }
        else
            flag_y = true;
    }
    cout<<result<<endl;
}

