// http://codeforces.com/problemset/problem/672/B
// AC
#include<cstdio>

int n;
char s[100010];
bool be[30];
int result;

int main(){

	scanf("%d%s",&n,s);
	if(n>26){
		printf("-1\n");
	}
	else{
		for(int i=0;i<26;i++){
			be[i]=false;
		}
		result=0;

		for(int i=0;i<n;i++){
			if(be[s[i]-'a']){
				result++;
			}
			else{
				be[s[i]-'a']=true;
			}
		}

		printf("%d\n",result);
	}

	return 0;
}