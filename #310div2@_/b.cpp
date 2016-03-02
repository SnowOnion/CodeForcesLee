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

#define __ printf("------------------------------------------\n");

#define f0n_1(_x,n) for(int _x=0;_x<n;_x++)
#define f1n_1(_x,n) for(int _x=1;_x<n;_x++)
#define f0n(_x,n) for(int _x=0;_x<=n;_x++)
#define f1n(_x,n) for(int _x=1;_x<=n;_x++)
#define fn_10(_x,n) for(int _x=n-1;_x>=0;_x--)
#define fn_11(_x,n) for(int _x=n-1;_x>0;_x--)
#define fn0(_x,n) for(int _x=n;_x>=0;_x--)
#define fn1(_x,n) for(int _x=n;_x>0;_x--)

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

/** Õâ¸ö¿´ÆðÀ´ÏñÊÇÉÏÏÞ? 8G 32Î» µÈµÈ ËÆºõÓÐµãÉµ±Æ
Ò»¸ö¿ª´óÁË²»ÐÐ ¿ª¶à¸öÈ´¿ÉÒÔ... */
// int viola[500000];
//    int viola2[500000];
//    int viola3[500000];
//    int viola4[500000];
//    int viola5[500000];

void test(){

}

void init(){

}

/** -(-1)^k * x */
int op(int k,int x){
    return (k%2)?x:-x;
}

void solve(){

    int n;
    int s[1010];
    inint(&n);
    for(int i=1;i<=n;i++){
        inint(&s[i]);
    }

    bool result=true;
    int times=n-s[1];

    for(int i=2;i<=n;i++){
        // printf("i:%d-s[i]:%d-op:%d\n",i,s[i],op(i,times));
        if((s[i]+op(i,times)+n)%n == (i-1)){
            continue;
        }
        else{
            result=false;
            break;
        }
    }

    printf("%s\n",result?"Yes":"No");
}   

int main(){
    test();
    init();
    solve();

    return 0;
}
