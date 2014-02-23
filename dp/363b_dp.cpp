#include<cstdio>

#define N 100+10
#define INF 1<<30 // yep.. not 31

//@status ing
//I'm deleting all that i can 

int main()
{
	int n,k,h[N];
	int dp[N];// dp[k] denotes \sum_{i=1}^{k} h[i]

	scanf("%d%d",&n,&k);

	dp[0]=0;
	int minIndex=1,minSum=INF;
	for(int i=1;i<=n;++i){
		scanf("%d",&h[i]);
		dp[i]=dp[i-1]+h[i];
		if(i>=k){
			// printf("%d>%d\n",i,k);
			if(dp[i]-dp[i-k]<minSum){
				minSum=dp[i]-dp[i-k];
				minIndex=i-k+1;
				// printf("new: minSum: %d, minIndex: %d\n",minSum,minIndex);
			}
		}
	}

	printf("%d\n", minIndex);

	return 0;
}