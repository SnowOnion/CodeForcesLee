#include<cstdio>
#include<cstring>


int n=0;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,   4,9,25,49};//,53,59,61,67,71};
char ans[100];
int main(){

	int i;
	for(i=0;i<19;i++){
		printf("%d\n",p[i]);
		fflush(stdout);
		scanf("%s",ans);
		if(!strcmp(ans,"yes")){
			n+=1;
			if(n>=2){
				printf("composite\n");
				fflush(stdout);
				break;
			}
		}
	}
	if(i==19){ // fuck!
				printf("prime\n");
				fflush(stdout);
	}

}