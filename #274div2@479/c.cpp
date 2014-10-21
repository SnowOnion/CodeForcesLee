#include<cstdio>
#include<algorithm>
using namespace std;

struct P{
    int nor;
    int ear;
};

bool cmp(P a, P b){
    return a.nor==b.nor?a.ear<b.ear:a.nor<b.nor;
}

int main(){

    int n;
    P ab[5010];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&(ab[i].nor),&(ab[i].ear));
    }

    sort(ab,ab+n,cmp);

//    for(int i=0;i<n;i++){
//        printf("%d %d\n",ab[i].nor,ab[i].ear);
//    }

    int rst=ab[0].ear;
    for(int i=1;i<n;i++){
        if(ab[i].ear < rst){ // Ôç¿¼Ð¡Ê§°Ü
            rst=ab[i].nor; // Çü×ðÍí¿¼
        }
        else{
            rst=ab[i].ear; // ÄÜÔç¾ÍÔç
        }
    }

    printf("%d\n",rst);

    return 0;
}

