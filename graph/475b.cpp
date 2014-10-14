/**
WA at test 16!
http://codeforces.com/contest/475/submission/8223685

16 11
<<<<>><><<<<<><<
vv^v^vvvv^v

output YES
answer NO

*/


#include<cstdio>

/**Floyd 算法. A 权值, D最终是最短距离*/
int A[410][410],D[410][410];
const int inf=1000000;
int rowarr[30],colarr[30];// 1: > ^ ; -1: < v

int n,m;

/**safe assign something to A*/
void assa(int val,int i,int j){
    if(0<=i && i<n*m && 0<=j && j<n*m){
        A[i][j]=val;
        /////////// copy to D
        D[i][j]=val;
    }
}

int main(){

    scanf("%d%d",&n,&m);
    char inp[30];
    scanf("%s",inp); // %c sucks
    for(int i=0;i<n;i++){
        rowarr[i]=inp[i]=='>'?1:-1;
    }
    scanf("%s",inp);
    for(int i=0;i<m;i++){
        colarr[i]=inp[i]=='^'?1:-1;
    }

    // calc A[i][j], copy to D[i][j]
    for(int i=0;i<n*m;i++){
        int xarr = rowarr[i/m];
        int yarr = colarr[i%m];
        for(int j=0;j<n*m;j++){
            if(i==j) assa(0,i,j);
            else if(j==i-1) assa(xarr==1?inf:1,i,j);
            else if(j==i+1) assa(xarr==1?1:inf,i,j);
            else if(j==i-m) assa(yarr==1?1:inf,i,j);
            else if(j==i+m) assa(yarr==1?inf:1,i,j);
            else assa(inf,i,j);
        }
    }

    for(int k=0;k<n*m;k++){
        for(int i=0;i<n*m;i++){
            for(int j=0;j<n*m;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }

/*
    for(int i=0;i<n*m;i++){
        printf("\n--%d--\n",i);
        for(int j=0;j<n*m;j++){
            if(!(j%m)) puts("");
            printf("%d ",D[i][j]);
        }
    }
*/
    int maxx=0,mi,mj;

    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(D[i][j]>maxx) {maxx=D[i][j];mi=i;mj=j;}
            /*
            if(D[i][j]>=inf){
                printf("NO\n");
                return 0;
            }*/
        }
    }

    printf("%d %d %d\n",mi,mj,maxx);



    printf("YES\n");
    return 0;
}
