/**AC http://codeforces.com/problemset/problem/472/A*/
#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    switch(n%4){
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
