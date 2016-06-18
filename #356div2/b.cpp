#include<cstdio>

#define smaller(a,b) a<b?a:b

int inint(int* d){
	return scanf("%d",d);
}


int n,a;
int t[110];
int main(){
	
	// int sum=0;
	// for(int i=0;i<110;i++){
	// 	times[i]=0;
	// }
	inint(&n);
	inint(&a);

// index from 1
	for(int i=1;i<=n;i++){
		inint(t+i);
	}

	bool left_or_mid = a<=(n/2+n%2);
	int rst=0;

	// 1
	rst+=t[a];
	//2
	for(int k=1;k<=(left_or_mid?(a-1):(n-a));k++){
		if((t[a-k]==1) && (t[a+k]==1)){
			rst+=2;
		}
	}
	//3
	if(left_or_mid){
		for(int x=2*a;x<=n;x++) rst+=t[x];
	}else{
		for(int x=1;x<=2*a-n-1;x++) rst+=t[x];	
	}

	

	printf("%d\n",rst);

}