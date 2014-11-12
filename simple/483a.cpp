#include<cstdio>
typedef long long LL;

int main(){

    LL l,r;
    scanf("%I64d%I64d",&l,&r);
    if(r-l<2){
        puts("-1");
    }
    else if((r-l==2)&&(l==1)){
        puts("-1");
    }
    else{
        printf("%I64d %I64d %I64d\n",r-2,r-1,r);
    }
    return 0;
}
