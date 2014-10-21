#include<cstdio>
#include<memory.h>

int main(){
    int inp[10];
    int a[10];

    memset(a,0,sizeof(a));
    for(int i=0;i<6;i++){
        scanf("%d",&inp[i]);
        a[inp[i]]++;
    }

    int has2=0,has4=0;

    for(int i=1;i<=9;i++){
            if(a[i]==6){
                printf("Elephant\n");
                return 0;
            }
        if(a[i]==5){
            printf("Bear\n");
            return 0;
        }
        if(a[i]==2){
            has2=1;
        }
        if(a[i]==4){
            has4=1;
        }
    }

    if(has2&&has4){
         printf("Elephant\n");
    }
    else if(has4){
        printf("Bear\n");
    }
    else{
        printf("Alien\n");
    }


    return 0;
}
