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

int inint(int* in)
{
    return scanf("%d",in);
}

int indouble(double* in)
{
    return scanf("%lf",in);
}

/** 这个看起来像是上限? 8G 32位 等等 似乎有点傻逼
一个开大了不行 开多个却可以... */
// int viola[500000];
//    int viola2[500000];
//    int viola3[500000];
//    int viola4[500000];
//    int viola5[500000];

void test()
{

}

int M,N;
int B[110][110];
int A[110][110];
int zr[110];
int zc[110];

void init()
{
    inint(&M);
    inint(&N);
    f0n_1(i,M)
    {
        f0n_1(j,N)
        {
            inint(&B[i][j]);
        }
    }
    // if not set to 0, is 1 // @GET memset 1 is not valid!!!!!!
    memset(A,-1,sizeof(A));
    memset(zr,0,sizeof(zr));
    memset(zc,0,sizeof(zc));

    //printMatrix(A,M,N);
}

void solve()
{
    // set 0
    f0n_1(i,M)
    {
        f0n_1(j,N)
        {
            if(!B[i][j])
            {
                f0n_1(p,M)
                {
                    A[p][j]=0;
                }
                f0n_1(q,N)
                {
                    A[i][q]=0;
                }
                zr[i]=1;
                zc[j]=1;
            }
        }
    }

    int contra=0;
    // check "zero grid"

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(zr[i]&&zc[j])
                if(B[i][j]!=0)
                    contra=1;

            if(A[i][j]==-1){
                A[i][j]=1;
            }
        }
    }


    if(contra)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
        printMatrix(A,M,N);
    }
}

int main()
{
    test();
    init();
    solve();

    return 0;
}
