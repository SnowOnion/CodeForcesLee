#include<cstdio>
typedef long long LL;

int main(){

    LL n;
    scanf("%I64d",&n);
    if(n%2){
        printf("%I64d\n",(n-1)/2-n);
    }
    else{
        printf("%I64d\n",n/2);
    }

    return 0;
}
