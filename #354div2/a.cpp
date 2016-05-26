#include<cstdio>

// #define and(a,b) (a)&&(b)
// #define mini(a,b) ((a)<(b)?(a):(b))
// #define maxi(a,b) ((a)>(b)?(a):(b))

int main(){
	
	int n;
	int a[110];
		scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}

	int min=111,max=-10;
	for(int i=1;i<=n;i++){
		if(a[i]==1) min=i;
		if(a[i]==n) max=i;
	}

	int result=0;

	int b[10];// 四种换法试一下...
	b[0]=min-1;
	b[1]=n-min;
	b[2]=max-1;
	b[3]=n-max;
	for(int i=0;i<4;i++){
		if(result<b[i]) result=b[i];
	}

	printf("%d\n",result);

	// if(n%2){ // 奇数

	// }
	// else{
	// 	if(and(min<=n/2,max<=n/2)){
	// 		result=n-mini(min,max);
	// 	}else if(and(min>=n/2,max>=n/2)){
	// 		result=maxi(min,max)-1;
	// 	}
	// 	else if(and(min<=n/2,max>=n/2)){
	// 		result=n/2-min>
	// 	}
	// }

	return 0;
}