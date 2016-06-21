/**AC*/

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

class cons{
    public:
    int i;
    string s;
    cons(){}
    cons(int ii,string ss){i=ii;s=ss;}
};

cons cs[200010];
int req[100010];

int cmp(cons a,cons b){
    return a.s<b.s;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string f,l;
        cin>>f>>l;
        cs[2*i-1]=cons(i,f);
        cs[2*i]=cons(i,l);
    }

    for(int i=0;i<n;i++){
        cin>>req[i];
    }

    sort(cs+1,cs+2*n+1,cmp);

//    for(int i=1;i<=n;i++){
//        cout<<i<<"--"<<endl
//        <<cs[2*i-1].i<<"--"<<cs[2*i-1].s<<endl
//        <<cs[2*i].i<<"--"<<cs[2*i].s<<endl;
//    }

/** Greed is good. */

    int act=1; // [1,2n]
    for(int i=0;i<n;i++){
        while(cs[act].i != req[i]){
            act++;
            if(act>2*n){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
