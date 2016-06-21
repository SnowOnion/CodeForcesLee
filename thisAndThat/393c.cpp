#include<cstdio>
#include<math.h>

using namespace std;

#define N 40000000+10

// double w[N][N],a[N][N],b[N][N];
int n;

// when n=0?

// from (n,0). up, up-left, left. to (0,n)

double d(int x,int y){
	return 	sqrt(x*x+y*y);
}

int main(){
	printf("%d",45000*45000);//motherfucker overflow
	scanf("%d",&n);

	if(!n){
		puts("1");
		return 0;
	}

	int x=n,y=0;
	// printf("%lf",d(x,y));
	int edger=0;
	while(!((x==0)&&(y==n))){
		if(y==x){
			edger++;
			break;
		}
		if(y>x){
			break;
		}

		if(d(x,y+1)-n<0.000001){
			// puts("UUUUUUUUUUUUU");
			edger++;
			y++;
		}
		else if(d(x-1,y+1)-n<0.000001){
			// puts("up-left");
			edger++;
			x--;
			y++;
		}
		else{
			// puts("--------------------left");
			edger++;
			x--;
		}
	}
	// printf("%d\n", edger*4);
	printf("%d\n", edger*8);

	return 0;
}