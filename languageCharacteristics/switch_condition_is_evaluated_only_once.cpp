/**AC http://codeforces.com/problemset/problem/472/A*/
#include<cstdio>

int f(int n){
    printf("unlike multi if-elseif-...-elseif-else, the condition expression(?) will be evaluated only once, see: %d\n",n);
    return n%4;
}

int main(){
    int n;
    scanf("%d",&n);
    switch(f(n)){
    case 0:
        printf("%d %d\n",n/2,n/2);
        break;
    case 2:
        printf("%d %d\n",n/2-1,n/2+1);
        break;
    default:
        printf("9 %d\n",n-9);
        break;
    }
    return 0;
}
