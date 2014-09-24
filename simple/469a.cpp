#include<cstdio>
#include<memory.h>

int ini(int* in){
    scanf("%d",in);
}

#define f1n(i,n) for(int i=1;i<=n;i++)

int main(){
    int n,p,q,pp[110];
    int in;
    memset(pp,0,sizeof(pp));

    ini(&n);
    ini(&p);
    while(p--){
        ini(&in);
        pp[in]=1;
    }
    ini(&q);
    while(q--){
        ini(&in);
        pp[in]=1;
    }

    do{
        if(!pp[n]){
            puts("Oh, my keyboard!");
            return 0;
        }
    }while(--n);

    puts("I become the guy.");
    return 0;
}
