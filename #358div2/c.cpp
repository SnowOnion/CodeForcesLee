#include<memory.h>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;

const double eps=1e-8;
const double pi=atan(1.0)*4;
const int inf=2147483600;
int tenpower[7]= {1,10,100,1000,10000,100000,1000000};
// pow10 is dangerous

typedef long long LL;

#define __ printf("------------------------------------------\n");

#define f0n_1(_x,n) for(int _x=0;_x<n;_x++)
#define f1n_1(_x,n) for(int _x=1;_x<n;_x++)
#define f0n(_x,n) for(int _x=0;_x<=n;_x++)
#define f1n(_x,n) for(int _x=1;_x<=n;_x++)
#define fn_10(_x,n) for(int _x=n-1;_x>=0;_x--)
#define fn_11(_x,n) for(int _x=n-1;_x>0;_x--)
#define fn0(_x,n) for(int _x=n;_x>=0;_x--)
#define fn1(_x,n) for(int _x=n;_x>0;_x--)

#define maxi(a,b) (a>b?a:b)

/**
    int a[][3]={{1,2,3},{4,5,6}};
    int b[][3]={9,8,7,6,5,4};

    printMatrix(a,2,3);
    __
    printMatrix(b,2,3);
    __
    printArray(b[1],3);
*/
#define printArray(lst,len) f0n_1(_i,(len)){printf("%d ",lst[_i]);} puts("");
#define printMatrix(mat,row,col) f0n_1(_j,(row)){printArray(mat[_j],(col));}

int inint(int* in){
    return scanf("%d",in);
}

int indouble(double* in){
    return scanf("%lf",in);
}

/** 这个看起来像是上限? 8G 32位 等等 似乎有点傻逼
一个开大了不行 开多个却可以... */
// int viola[500000];
//    int viola2[500000];
//    int viola3[500000];
//    int viola4[500000];
//    int viola5[500000];

void test(){
    // printf("%s\n", "hellp");
}

int n;
LL a[100010],c[100010];
vector<int> son[100010];

void init(){
    inint(&n);
    f1n(i,n){
        cin>>a[i];
    }
    f1n_1(i,n){
        int p;
        cin>>p;
        son[p].push_back(i+1);
        cin>>c[i+1];
    }
}


// count subnodes(including self)
int del(int i){
    if(son[i].size()==0){
        return 1;
    }
    else{
        int sum=1;
        for(auto iter=son[i].begin();iter!=son[i].end();++iter){
                sum+=del(*iter);
        }
        return sum;
    }
}

// remove how many?
// f(1,0)
int f(int i,LL dpi){
    int result=0;
    for(auto iter=son[i].begin();iter!=son[i].end();++iter){
        LL dson=dpi+c[*iter];
        if(dson>a[*iter]){
            result+=del(*iter);
        }
        else{
            result+=f(*iter,maxi(dson,0));
        }
    }
    return result;
}



void solve(){
    printf("%d\n", f(1,0));
}



int main(){
    test();
    init();
    solve();

    return 0;
}
