/** AC http://codeforces.com/problemset/problem/472/B */
#include<cstdio>
#include<algorithm>
using namespace std;

// 2<=fi<=2000 | 1<=n,k<=2000
int f[2010];

bool cmp(int a,int b){
    return a>b;
}

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&f[i]);
    }
    sort(f,f+n,cmp);

    int total=0;
    for(int i=0;i<n;i+=k){
        //printf("--%d--%d\n",i,f[i]);
        total+=(f[i]-1)*2;
    }

    printf("%d\n",total);
    return 0;
}
