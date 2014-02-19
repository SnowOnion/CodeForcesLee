#include<cstdio>
#include<math.h>

using namespace std;

#define N 40000000+10

// double w[N][N],a[N][N],b[N][N];
int n;

// when n=0?

// from (n,0). up, up-left, left. to (0,n)

// double d(int x,int y){
// 	return 	sqrt(x*x+y*y);
// }

int main(){
	// printf("%d",45000*45000);//motherfucker overflow
	scanf("%d",&n);

	if(!n){printf("%d\n", 1);}
	else if(n==1){printf("%d\n", 4);}
	else{
		printf("%d\n", 8*(int)(n/sqrt(2)));
	}
	
	return 0;
}