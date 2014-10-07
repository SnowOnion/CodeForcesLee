
#include<cstdio>
#include<memory.h>

int isp[200000010];

int isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(!(x%i)) {
            //printf("%d is NOT prime\n",x);
            isp[x]=0;
            return 0;
        }
    }
    //printf("%d is prime\n",x);
    isp[x]=1;
    return 1;
}



int main(){

        int n;
    int xs[100010];//10^6
    int m;
    int l[50010],r[50010];

    memset(isp,-1,200000010*sizeof(int));

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&xs[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d%d",&l[i],&r[i]);

    //printf("%d,%d",x[5],r[1]);

//    for(int i=0;i<m;i++){
//        printf("%d %d\n",l[i],r[i]);
//    }

    int ans;
    for(int q=0;q<m;q++){
        ans=0;
        for(int i=l[q];i<=r[q];i++){
//            printf("-------------this is i:%d\n");
            if(isp[i]==-1?isPrime(i):isp[i]){
                for(int j=0;j<n;j++){
                    if(!(xs[j]%i)){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
