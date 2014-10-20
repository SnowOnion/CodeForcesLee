#include<cstdio>

int main(){

    int n,k;
    int a[110];
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int m=0;
    int maxi,mini;
    int ins;
    int from[10010],to[10010];
    while(m<k){
        maxi=1,mini=1;
        for(int i=1;i<=n;i++){
            if(a[maxi]<a[i]) maxi=i;
            if(a[mini]>a[i]) mini=i;
        }
        //printf("m=%d maxi=%d maxval=%d mini=%d minval=%d\n",m,maxi,a[maxi],mini,a[mini]);
        ins=a[maxi]-a[mini];
        if(ins<=1) break;
        else{
            from[m]=maxi; to[m]=mini;
            a[maxi]--; a[mini]++;
            m++;
        }
    }

    // 丑陋地再数一遍
    maxi=1,mini=1;
    for(int i=1;i<=n;i++){
        if(a[maxi]<a[i]) maxi=i;
        if(a[mini]>a[i]) mini=i;
    }
    //printf("m=%d maxi=%d maxval=%d mini=%d minval=%d\n",m,maxi,a[maxi],mini,a[mini]);
    ins=a[maxi]-a[mini];

    printf("%d %d\n",ins,m);
    for(int i=0;i<m;i++){
        printf("%d %d\n",from[i],to[i]);
    }

    return 0;
}

