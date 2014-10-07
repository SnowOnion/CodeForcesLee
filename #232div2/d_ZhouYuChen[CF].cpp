//author ZhouYuChen @codeforces
// QJYQ de jerk...

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime(ll n){
	if(n==1)return 0;
	for(int j=2;j*j<=n;j+=1+(j&1))
		if(n%j==0)return 0;
	return 1;
}
void solve(ll n){
	ll l=n,r=n+1;
	for(;!prime(l);--l);
	for(;!prime(r);++r); 
	ll p=r*l-r*2+2*(n-l+1), q=r*l*2,g=__gcd(p,q);
	cout << p/g << "/" << q/g << endl;
}
int main(){
	int T,a;
	for(cin >> T;T--;solve(a))cin >> a;
}