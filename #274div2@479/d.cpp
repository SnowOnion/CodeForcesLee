#include<cstdio>
#include<algorithm>
using namespace std;

/**�����ְ�����*/
/**ԭ���汾pretest 4 WA, Ҳ��.*/


int main(){

    int n,l,x,y;
    int a[100010];

    scanf("%d%d%d%d",&n,&l,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int s;
    int fx=0,fy=0,fxy=0;
    int xys,xye; // �ҵ�x+yʱ��

    // ��֮��ֵ������
    // ��x
    int tar=x;
    int found=0;
    int low,high,mid;
    for(s=1;s<=n-1;s++){
        low=s+1;
        high=n;
        while(true){
            mid=(low+high)/2;
            if(low==mid){
                if((tar==a[low]-a[s])||(tar==a[high]-a[s])){
                    found=1;
                }
                break;
            }

            if(tar<a[mid]-a[s]){
                high=mid;
            }
            else if(tar>a[mid]-a[s]){
                low=mid;
            }
            else{// �ҵ���
                found=1;
                break;
            }
        }
        if(found){
            fx=1;
            break;
        }
    }

    //printf("fx=%d s=%d mid=%d\n",fx,s,mid);

    // ��y
    tar=y;///////////
    found=0;

    for(s=1;s<=n-1;s++){
        low=s+1;
        high=n;
        while(true){
            mid=(low+high)/2;
            if(low==mid){
                    if((tar==a[low]-a[s])||(tar==a[high]-a[s])){
                    found=1;
                }
                break;
            }

            if(tar<a[mid]-a[s]){
                high=mid;
            }
            else if(tar>a[mid]-a[s]){
                low=mid;
            }
            else{// �ҵ���
                found=1;
                break;
            }
        }
        if(found){
            fy=1;////////////////
            break;
        }
    }

    //printf("fy=%d s=%d mid=%d\n",fy,s,mid);

    // ��xy
    tar=x+y;////////////////
    found=0;

    for(s=1;s<=n-1;s++){
        low=s+1;
        high=n;
        while(true){
            mid=(low+high)/2;
            if(low==mid){
                    if((tar==a[low]-a[s])||(tar==a[high]-a[s])){
                    found=1;
                }
                break;
            }

            if(tar<a[mid]-a[s]){
                high=mid;
            }
            else if(tar>a[mid]-a[s]){
                low=mid;
            }
            else{// �ҵ���
                found=1;
                break;
            }
        }
        if(found){
            fxy=1;//////////
            xys=s;xye=mid;//////////////
            break;
        }
    }

    //printf("fxy=%d s=%d mid=%d\n",fxy,s,mid);

    if(fx&&fy){
        printf("0\n");
    }
    else if(fx&&(!fy)){
        printf("1\n%d\n",y);
    }
    else if((!fx)&&fy){
        printf("1\n%d\n",x);
    }
    else if(fxy){
        printf("1\n%d\n",a[xys]+x);
    }
    else{
        printf("2\n%d %d\n",x,y);
    }

    return 0;
}

