//#include <iostream>
//using namespace std;
//
//int main(){
//    int n, m, k;
//    int x=0, y=0;
//    int cnt=-1;
//    cin>>n>>m>>k;
//
//    if(k==0){
//        cout<<x<<' '<<y<<endl;
//    }
//    else{
//        while(k>=0){
//            k -= m;
//            cnt++;
//            x = cnt;
//        }
//        y = k+m;
//
//        cout<<x<<' '<<y<<endl;
//    }
//}

#include <iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int m2=0;
    int k2=0;
    int n2=0;
    while(k2<n*m)
    {
        m2=0;
        if(k==k2){
            cout<<n2<<' '<<m2;
            return 0;
        }
        while(m2<m)
        {
            if(k2==k)
            {
                cout<<n2<<' '<<m2;
                return 0;
            }
            m2+=1;
            k2+=1;
        }
        n2+=1;
    }
}
