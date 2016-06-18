#include<cstdio>

#define smaller(a,b) a<b?a:b

int inint(int* d){
	return scanf("%d",d);
}


int inp[10];
int times[110];
int main(){
	
	int sum=0;
	for(int i=0;i<110;i++){
		times[i]=0;
	}
	for(int i=0;i<5;i++){
		inint(inp+i);
		times[inp[i]]+=1;
		sum+=inp[i];
	}

	int max=0;
	for(int i=1;i<=100;i++){
		if((times[i]>=2)){
			int v=i*(smaller(times[i],3));
			if(max<v) max=v;
		}
	}

	printf("%d\n",sum-max);

}