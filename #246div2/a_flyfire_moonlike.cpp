// http://blog.csdn.net/flyfire_moonlike/article/details/25933225

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define Cmp(a,b) strcmp(a,b)
#define Copy(a,b) strcpy(a,b);
#define Len(a) strlen(a);
#define sn getchar()
#define fr(a) for(int i=0;i<n;i++)
#define fn(a) for(int i=1;i<=n;i++)
#define f1(a) for(int i=1;i<n;i++)
#define pn cout<<endl
#define pc(a) printf("Case %d:",a)
#define pr cout<<" "
#define MEM(a) memset(a,0,sizeof(a))
#define MEMF(a) memset(a,false,sizeof(a))
#define w1 while(1)
#define w(a) while(a--)
#define INF 4294967295
#define PI 3.14159265359

const int dir4[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
const int dir8[8][2]= {{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};

/***********************************************/

int main()
{
    int n,k;
    int peo[2001];
    MEM(peo);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>peo[i];
    }
    int sum=0;
    sort(peo,peo+n);
    for(int i=2;i<n;i+=3)
    {
        if(peo[i]+k<=5)
            sum++;
    }
    cout<<sum<<endl;;
    return 0;
}
