/**
shorten test 25
121 1930 1785 1818
0 3 8 24 35 39 48 55 71 78 91 97 100 103 110 129 137 139 141 147 155 163 178 183 186 214 220 225 257 260 268 272 303 321 348 353 380 395 447 457 479 481 502 510 525 532 550 555 562 574 587 589 598 610 634 647 670 671 673 674 687 694 707 716 723 732 739 743 747 752 755 757 778 805 807 817 818 822 835 838 852 856 870 878 905 928 931 944 951 953 956 960 962 963 985 994 996 1000 1008 1011 1020 1023 1026 1029 1044 1054 1076 1077 1090 1095 1149 1163 1164 1166 1177 1178 1192 1201 1837 1870 1930

wrong:
2
1785 1818
right:
1
52

AC!!! 不容易. http://codeforces.com/contest/479/submission/8324782
*/

#include<cstdio>

int n,l,x,y;
int a[100010];

/**
[l,r]
ret -1 while missing
*/
int binary_search_lee(int val,int l,int r){
    while(l<=r){
        /**necessary? m=(l+r)/2 */
        int m=(r-l)/2 + l;
//        printf("val %d  l %d r %d m %d\n",val,l,r,m);
        if(val>a[m]) l=m+1;
        else if(val<a[m]) r=m-1;
        else return m;
    }
    return -1;
}

int main(){

    scanf("%d%d%d%d",&n,&l,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int s;
    int fx=0,fy=0,fxy=0;//,fyx=0; // whether find x, y, x+y, y-x
    int rstx,rsty;
    int x_plus_y_end;
    int y_minus_x_end;

    // 手工的队列
    int yx_num=0;
    int yx_end_set[10010];

    for(s=1;s<=n-1;s++){
        if(!fx) fx =  (-1 != ( rstx = binary_search_lee(a[s]+x,s,n)));
        if(!fy) fy =  (-1 != ( rsty = binary_search_lee(a[s]+y,s,n)));
        if(!fxy)fxy = (-1 != ( x_plus_y_end  = binary_search_lee(a[s]+x+y,s,n) ) );
        if (-1 != ( y_minus_x_end = binary_search_lee(a[s]+y-x,s,n) ) ){
            yx_end_set[yx_num]=y_minus_x_end;
            yx_num++;
        }
        // 当时做的时候没考虑到最后这种 inspired by xking
        // 还是没考虑全... 从残缺的test 25 抠出测试数据明白了. y_minus_x_end 有风险, 不是找出一个就可以的.
        // 单独拎出来吧. 妈的 还得改造 binary search. 不, 改造s循环.
    }

//    printf("rstx-%d rsty-%d xpy-%d yms-%d\n",rstx,rsty,x_plus_y_end,y_minus_x_end);
//    printf("fx-%d fy-%d fxy-%d fyx-%d\n",fx,fy,fxy,fyx);


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
        printf("1\n%d\n",a[x_plus_y_end]-x);
    }
    else if(yx_num>0){
//        printf("a[y_minus_x_end]:%d x:%d a[y_minus_x_end]+x:%d 0:%d\n",a[y_minus_x_end],x,a[y_minus_x_end]+x,l);
//    printf("a[y_minus_x_end]:%d y:%d a[y_minus_x_end]-y:%d 0:%d\n",a[y_minus_x_end],y,a[y_minus_x_end]-y,0);
        int i;
        for(i=0;i<yx_num;i++){
            // 含义改变
            y_minus_x_end=yx_end_set[i];
            if(a[y_minus_x_end]+x<l){ // if == l, fx&&fy==true
                printf("1\n%d\n",a[y_minus_x_end]+x);
                break;
            }
            else if(a[y_minus_x_end]-y>0){ // if == 0, fx&&fy==true
                printf("1\n%d\n",a[y_minus_x_end]-y);
                break;
            }
        }
        if(i==yx_num){ // 无一合适
            printf("2\n%d %d\n",x,y);
        }
//        if(a[y_minus_x_end]+x<l){ // if == l, fx&&fy==true
//            printf("1\n%d\n",a[y_minus_x_end]+x);
//        }
//        else if(a[y_minus_x_end]-y>0){ // if == 0, fx&&fy==true
//            printf("1\n%d\n",a[y_minus_x_end]-y);
//        }
//        else{
//            printf("2\n%d %d\n",x,y);
//        }
    }
    else{
        printf("2\n%d %d\n",x,y);
    }

    return 0;
}
