/**
author: BearChild
http://blog.csdn.net/keshuai19940722/article/details/18894143
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 100005;
int n, v[N], c[N];
char num[N];

void init () {
	n = 0;
	memset(v, 0, sizeof(v));
	memset(c, 0, sizeof(c));
	scanf("%s", num);

	int x = 0;
	for (int i = strlen(num) - 1; i >= 0; i--) {
		x++;
		if (num[i] != '0') {
			c[n] = x; v[n] = num[i] - '0'; // c[n]表位数, v[n]表最高位
			n++; x = 0;
		}
	}
}

// c 和 v 的"从头到尾"表示原串的"从右向左"

int solve () {
	int ans = 1;
	int cnt = c[n-1], val = v[n-1];
	for (int i = n-2; i >= 0; i--) {
		if (cnt > c[i] || (cnt == c[i] && val >= v[i])) ans++;
		else ans = 1; // 前面滚起来的都不够看. 必须和第i个"本来就在一起".
		cnt += c[i]; //每次??? //哦.. 按规则滚雪球.. 正确.. 我为什么想出那种鬼畜拆法?
	}
	return ans;
}

int main () {
	init();
	printf("%d\n", solve());
	return 0;
}
