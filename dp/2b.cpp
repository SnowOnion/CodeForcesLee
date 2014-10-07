//20:30
//@status give up at 21:50. "1h and find a excellent solution".
//learn: 关心 1. 贪心那步 2. 双状态表示
#include<cstdio>
#include<iostream>
using namespace std;

#define N (1000+10)

class State
{
public:
	int n2;
	int n5;
	State(int nn2,int nn5){n2=nn2;n5=nn5;}
	bool operator<(State& otherState){
		return (n2<otherState.n2)||(n5<otherState.n5);
	}// 不对啊!!! 一大一小怎么办!!
	int ten(){
		return n2<n5?n2:n5;
	}
};


int n;
int m[N][N];
int vis[N][N];
int INF=N*N;
State* s[N][N];
State* INFS;
char go[N][N];


void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&m[i][j]);
			s[i][j]=new State(INF,INF);/*错误地初始化成了(-1,-1)
			结果人人都是很优の解... 特殊值不能是可能出现的值,也不能影
			响判断... 状态一复杂就忘了这个原则...*/
		}
	}
	INFS=new State(INF,INF);
	memset(vis,0,sizeof(vis));
	for (int i = 0; i < n; ++i)
	{
		s[i][n]=new State(INF,INF);
		vis[i][n]=1;
		s[n][i]=new State(INF,INF);
		vis[n][i]=1;
	}// border
	s[n-1][n-1]=new State(m[n-1][n-1]==2?1:0,m[n-1][n-1]==5?1:0); // Root of evaluation
}

/**
这个值表示从(x,y)走到(n-1,n-1)的最好状态
*/
State* dp(int x,int y){
	// printf("dp %d,%d\n",x,y );
	if(vis[x][y]) return s[x][y];
	// printf("--EVAL %d,%d\n",x,y );

	// printf("@(%d,%d), goto (%d,%d)\n",x,y,x+1,y);
	State* rightS=dp(x+1,y);
	printf("dp(%d,%d)====={%d,%d}\n", x+1,y,rightS->n2,rightS->n5);

	// printf("@(%d,%d), goto (%d,%d)\n", x,y,x,y+1);
	State* downS=dp(x,y+1);
	printf("dp(%d,%d)====={%d,%d}\n", x,y+1,downS->n2,downS->n5);

	State* lesserS=(rightS->ten()<downS->ten())
	||
	((rightS->ten()==downS->ten())&&((*rightS)<(*downS)))?(go[x][y]='R',rightS):(go[x][y]='D',downS);// 这里好贪心啊!!!!! 能对吗!!!
	// FML
		
	vis[x][y]=1;
	if(m[x][y]==2)	return s[x][y]=new State(lesserS->n2+1,lesserS->n5);
	else if(m[x][y]==5)	return s[x][y]=new State(lesserS->n2,lesserS->n5+1);
	else return new State(lesserS->n2,lesserS->n5);

}


int main(){
	init();
	printf("%d\n", dp(0,0)->ten());

	int x=0,y=0;
	while(!((x==n-1)&&(y==n-1))){
		printf("%d,%d %c\n",x,y,go[x][y]);
		if(go[x][y]=='R') x++;
		else y++;
	}
	printf("\n");

	return 0;
}