#include<cstdio>

typedef long long LL;
const LL M=1000000007;

LL mulmod(LL a,LL b){
    return ((a%M)*(b%M))%M;
}

int main(){

    long long a,b;

    scanf("%I64d%I64d",&a,&b);

    long long rst= mulmod( mulmod(b,b-1)/2 , (a+ mulmod( mulmod(a,a+1)/2, b )));

    printf("%I64d\n",rst);

    return 0;
}

