/**
单行注释 as 调试痕迹;
多行注释 as 姿势;
不保留修改痕迹=.=
*/

// @status AC

#include<cstdio>
#include<memory.h>

#define N 4000+10
#define M 3
#define INF 2000000000

int n,a[M];
int DP[N];

void init(){
	memset(DP,-1,sizeof(DP));
	DP[0]=0;

	scanf("%d%d%d%d",&n,a,a+1,a+2);
}

int dp(int r){
	// printf("call %d\n", r);
	if(DP[r]!=-1) return DP[r];
	// printf("-Eval %d\n", r);
	DP[r]=-INF; 
	/*for testcase 100 23 15 50, 
	result=5 without "DP[r]=-100000; ",
	result=2 with "DP[r]=-100000; "*/

	for (int i = 0; i < M; ++i)
	{
		if(r>=a[i]){
			// printf("i'm %d, visiting %d\n",r,r-a[i] );
			int neighborDP=dp(r-a[i])+1; 
			/* @GET 
			If no "DP[r]=-100000", due to the
			"+1" here, a failure node will value -1+1=0
			then welcomed by the father node who 
			values -1. Which creates mistake.

			20140219
			*/
			if(DP[r]<neighborDP) {
				DP[r]=neighborDP;
				// printf("DP[%d] change to %d \n", r,DP[r]);
			}
		}
	}
	/* @GET 
	When all branches miss, failure happens, 
	so the return value should be "worst enough"
	to illustrate the failure.

	That's why we need "DP[r]=-100000" before 
	transfering to any branch.

	20140219
	*/

	return DP[r];
}

int main(){
	init();
	printf("%d\n",dp(n));
	return 0;
}