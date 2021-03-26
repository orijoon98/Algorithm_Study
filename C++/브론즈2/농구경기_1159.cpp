#include <iostream>
using namespace std;

int main(){
    int number;
    cin>>number;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0;
    int n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
    char *firstname = new char[number];
    for(int i=0;i<number;i++){
        string name;
        cin>>name;
        firstname[i] = name[0];
    }
    for(int A=0;A<number;A++){
        switch (firstname[A]) {
            case 'a':
                a++;
                break;
            case 'b':
                b++;
                break;
            case 'c':
                c++;
                break;
            case 'd':
                d++;
                break;
            case 'e':
                e++;
                break;
            case 'f':
                f++;
                break;
            case 'g':
                g++;
                break;
            case 'h':
                h++;
                break;
            case 'i':
                i++;
                break;
            case 'j':
                j++;
                break;
            case 'k':
                k++;
                break;
            case 'l':
                l++;
                break;
            case 'm':
                m++;
                break;
            case 'n':
                n++;
                break;
            case 'o':
                o++;
                break;
            case 'p':
                p++;
                break;
            case 'q':
                q++;
                break;
            case 'r':
                r++;
                break;
            case 's':
                s++;
                break;
            case 't':
                t++;
                break;
            case 'u':
                u++;
                break;
            case 'v':
                v++;
                break;
            case 'w':
                w++;
                break;
            case 'x':
                x++;
                break;
            case 'y':
                y++;
                break;
            case 'z':
                z++;
                break;
            default:
                break;
        }
    }
    delete[] firstname;

    if(a<5 && b<5 && c<5 && d<5 && e<5 && f<5 && g<5 && h<5 && i<5 && j<5 && k<5 && l<5 && m<5 && n<5 && o<5 && p<5 && q<5 && r<5 && s<5 && t<5 && u<5 && v<5 && w<5 && x<5 && y<5 && z<5){
        cout<<"PREDAJA"<<endl;
    }

    else{
        if(a>=5){
            cout<<'a';
        }
        if(b>=5){
            cout<<'b';
        }
        if(c>=5){
            cout<<'c';
        }
        if(d>=5){
            cout<<'d';
        }
        if(e>=5){
            cout<<'e';
        }
        if(f>=5){
            cout<<'f';
        }
        if(g>=5){
            cout<<'g';
        }
        if(h>=5){
            cout<<'h';
        }
        if(i>=5){
            cout<<'i';
        }
        if(j>=5){
            cout<<'j';
        }
        if(k>=5){
            cout<<'k';
        }
        if(l>=5){
            cout<<'l';
        }
        if(m>=5){
            cout<<'m';
        }
        if(n>=5){
            cout<<'n';
        }
        if(o>=5){
            cout<<'o';
        }
        if(p>=5){
            cout<<'p';
        }
        if(q>=5){
            cout<<'q';
        }
        if(r>=5){
            cout<<'r';
        }
        if(s>=5){
            cout<<'s';
        }
        if(t>=5){
            cout<<'t';
        }
        if(u>=5){
            cout<<'u';
        }
        if(v>=5){
            cout<<'v';
        }
        if(w>=5){
            cout<<'w';
        }
        if(x>=5){
            cout<<'x';
        }
        if(y>=5){
            cout<<'y';
        }
        if(z>=5){
            cout<<'z';
        }
        cout<<endl;
    }
}

