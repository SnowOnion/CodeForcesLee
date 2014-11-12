#include<cstdio>

int main(){

    int a,b,c;
    int rst[10];
    scanf("%d%d%d",&a,&b,&c);

    rst[0]=a+b+c;
    rst[1]=a+b*c;
    rst[2]=(a+b)*c;
    rst[3]=a*b+c;
    rst[4]=a*(b+c);
    rst[5]=a*b*c;

    int maxx=0;
    for(int i=0;i<6;i++){
        if(maxx<rst[i]) maxx=rst[i];
    }
    printf("%d\n",maxx);

    return 0;
}
