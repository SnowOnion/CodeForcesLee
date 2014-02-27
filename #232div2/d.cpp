#include<cstdio>
#include<memory.h>
// #include<vector>

// using namespace std;

// std::vector<int> Prime(100000010,-1);
// 500000000+
int Prime[500000010]; //OMG
int Prime2[500000010];

int prime(int n){
	// (int*)& P=(n>500000000?Prime2:Prime);

	if((n>500000000?Prime2[n-500000000]:Prime[n])!=-1){
		return (n>500000000?Prime2[n-500000000]:Prime[n]);
	}

	for(int i=2;i*i<=n;i+=1){
		if(prime(i)){
			if(n%i==0){
				return ((n>500000000?Prime2[n-500000000]:Prime[n])=0);
			}
		}
	}
	return ((n>500000000?Prime2[n-500000000]:Prime[n])=1);
}

void init(){
	memset(Prime,-1,sizeof(Prime));
	memset(Prime2,-1,sizeof(Prime2));
	Prime[2]=Prime[3]=1;

}

int main(){
	init();
	prime(100);
	for(int i=2;i<100;i++){
		printf("%d\t%d\n",i,prime(i));
	}
	return 0;
}