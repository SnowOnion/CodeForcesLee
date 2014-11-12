#include<cstdio>

int minn(int x,int y){
    return x<y?x:y;
}

int d(char a,char b){
    if(a-b<0){
        return minn((b-a),26-(b-a));
    }
    else{
        return minn((a-b),26-(a-b));
    }
}

int main(){
    int n,p;
    // from 0
    char str[100010];
    // from 1
    int D[100010];
    scanf("%d%d%s",&n,&p,str);

    for(int i0=0;i0<n/2;i0++){
        D[i0+1]=d(str[i0],str[n-1-i0]);
        //printf("%d ",D[i0+1]);
    }


    // 奇数个
    if(n%2){
        // 在右边
        if(p>(1+n/2)){
            // 对称到已知问题
            p=n+1-p;
        }
    }
    else{// 偶数个
            // 在右边
        if(p>n/2){
            p=n+1-p;
        }
    }

//    printf("%d",p);

//    for(int i=1;i<=n/2;i++){
//        printf("%d ",D[i]);
//    }
//    puts("---------");

    int ln=p,rn=p;
    for(int i=1;i<p;i++){
            /** OMG!!! d[i] is not a compile error!! @GET*/
        if(D[i]>0){
            ln=i;
            break;
        }
    }
    for(int i=n/2;i>p;i--){
        if(D[i]>0){
            rn=i;
            break;
        }
    }

//    printf("%d %d",ln,rn);

    int sum;
    if(p-ln>rn-p){
        sum=rn-p + rn-ln;
    }
    else{
        sum=p-ln + rn-ln;
    }
    for(int i=1;i<=n/2;i++){
        sum+=D[i];
    }

    printf("%d\n",sum);


    return 0;
}
