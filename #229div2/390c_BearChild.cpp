/**
Author: BearChild
http://blog.csdn.net/keshuai19940722/article/details/19170011
@status AC
*/

// Lee: 两坐标相减时, 抹平了 0-起始 和 1-起始 的区别...

#include <stdio.h> 
#include <string.h> 
#include <algorithm> 

using namespace std;
const int N = 100005;

int n, k, w, s[15][N];
char str[N];

/**
判断 x+mk开头时, y处是否需要处理. m属于自然数.
*/
bool judge(int x, int y) {
	if ((y - x + k + 1) % k == 0 && str[y-1] == '0') return true;
	if ((y - x + k + 1) % k != 0 && str[y-1] == '1') return true;
	return false;
}

void init () {
	memset(s, 0, sizeof(s));

	scanf("%d%d%d%s", &n, &k, &w, str);
	int len = strlen(str);

	for (int i = 0; i < k; i++) {
		for (int j = i+1; j <= len; j++) {
			s[i][j] = s[i][j-1];
			if (judge(i, j)) s[i][j]++;  //////////////////@GET DP: 复制与增长
		}
	}
}

/**
这一坨的全部原因就是init()没有判断"坐标l处是否需要处理"(而且solve时的相减实际上挖掉了l). 所以最后来判断这件事情..
*/
int handle(int x) {
	if (k == 1) {
		if (str[x-1] == '0') return 1;
	} else {
		if (str[x-1] == '1') return 1;
	}
	return 0;
}

void solve () {
	int x, y;
	for (int i = 0; i < w; i++) {
		scanf("%d%d", &x, &y);
		int t = x % k;
		printf("%d\n", s[t][y] - s[t][x] + handle(x));
	}
}

int main () {
	init ();
	solve();
	return 0;
}
