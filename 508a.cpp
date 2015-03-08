#include <cstdio>
#include <memory.h>

#define NN 1000+10
#define KK 10000+10

// 边界填充0。正片[1,n]*[1,m]
int mat[NN][NN];

bool is_black(int i, int j){
    return mat[i][j]==1;
}

// 在 i,j 被涂黑后检查
bool is_formed(int i, int j){
// left top, etc.
    bool tl=true,tr=true,bl=true,br=true;
    if(!is_black(i-1,j-1)){
        tl=false;
    }
    if(!is_black(i-1,j)){
        tl=false;
        tr=false;
    }
    if(!is_black(i-1,j+1)){
        tr=false;
    }
    if(!is_black(i,j+1)){
        tr=false;
        br=false;
    }
    if(!is_black(i+1,j+1)){
        br=false;
    }
    if(!is_black(i+1,j)){
        br=false;
        bl=false;
    }
    if(!is_black(i+1,j-1)){
        bl=false;
    }
    if(!is_black(i,j-1)){
        bl=false;
        tl=false;
    }
//    printf("tl %d tr %d bl %d br %d\n",tl,tr,bl,br);
    return tl || tr || bl || br;
}

int main(){
    
    memset(mat,0,sizeof(mat));
    
    bool formed=false;
    int halt_round=0;

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for(int c=0;c<k;c++){
        scanf("%d%d",&i,&j);
        mat[i][j]=1;
        if( (!formed) && is_formed(i,j)){
//            printf("formed, c=%d\n",c);
            formed=true;
            halt_round=c+1;
        }
    }
    
    printf("%d\n",halt_round);
    
    return 0;
}