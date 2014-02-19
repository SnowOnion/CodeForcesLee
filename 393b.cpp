#include<cstdio>

using namespace std;

#define N 170+10

double w[N][N],a[N][N],b[N][N];
int n;

int main(){
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&w[i][j]);
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=(w[i][j]+w[j][i])/2;
			b[i][j]=(w[i][j]-w[j][i])/2;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lf ",a[i][j]);
		}
		puts("");
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lf ",b[i][j]);
		}
		puts("");
	}

	return 0;
}