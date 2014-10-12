// #include<cstdio>
#include<iostream>
using namespace std;
#define N 100+10

//@status TLE
// I really don't freaking know why this TLE. I can't tell the diff between 
// this and #5058924 (first of http://codeforces.com/problemset/status/363/problem/B?csrf_token=d6g67145a9h8gh6de8ef70b883d174e8&order=BY_CONSUMED_TIME_ASC)

int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("data.txt", "r", stdin);
 //    #endif

	int n,k,h[N];
	// scanf("%d%d",&n,&k);
	cin>>n>>k;
	for(int iter=1;iter<=n;++iter){
		// scanf("%d",&h[iter]);
		cin>>h[iter];
	}

	int sum=0;
	for(int iter=1;iter<=k;++iter){
		sum+=h[iter];
	}

	int minIndex=1,minSum=sum;

	for(int left=1;left<=n-k;left++){
		sum-=h[left];
		sum+=h[left+k];
		if(sum<minSum){
			minSum=sum;
			minIndex=left+1;
		}
	}

	// printf("%d\n", minIndex);
	cout<<minIndex<<endl;

	return 0;
}