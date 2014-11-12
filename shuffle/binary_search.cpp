#include<cstdio>
#include<cstdlib> //rand()
#include<ctime>

int a[10010];

/** [0,n) */
void gen_test(int n){
    srand(time(NULL));
    int cur=0;
    for(int i=0;i<n;i++){
        cur+=rand();
        a[i]=cur;
        printf("%d\t%d\n",i,a[i]);
    }

}

/**
[l,r]
ret -1 while missing
*/
int binary_search_lee(int val,int l,int r){
    while(l<=r){
        /**necessary? m=(l+r)/2 */
        int m=(r-l)/2 + l;
        printf("l %d r %d m %d\n",l,r,m);
        if(val>a[m]) l=m+1;
        else if(val<a[m]) r=m-1;
        else return m;
    }
    return -1;
}

int main(){
    gen_test(100);
    int in;
    printf("Your target >>");
    scanf("%d",&in);
    printf("%d at %d\n",in,binary_search_lee(in,0,99));

    return 0;
}
