#include<stdio.h>

#define N 200010
#define INF 1000000000 

//@status AC
// i wrongly set N to be 100+10, which is the range of each height. 
// which cause secret TLE.
// Fuck my life.
// %l64d doesn't work in gcc?

int main()
{
	int n,k,hi;
	long long dp[N];// dp[k] denotes \sum_{i=1}^{k} h[i]
	int i;
	long long minIndex,minSum;

	scanf("%d%d",&n,&k);

	dp[0]=0;
	minIndex=1,minSum=INF;
	// printf("%l64d",minSum);
	for(i=1;i<=n;++i){
		scanf("%d",&hi);
		dp[i]=dp[i-1]+hi;
		if(i>=k){
			// printf("%d>%d\n",i,k);
			if(dp[i]-dp[i-k]<minSum){
				minSum=dp[i]-dp[i-k];
				minIndex=i-k+1;
				// printf("new: minSum: %l64d, minIndex: %d\n",minSum,minIndex);
			}
		}
	}

	printf("%d\n", minIndex);

	return 0;
}