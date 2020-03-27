//#include <bits/stdc++.h>

#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
ll ksm(ll a, ll b)
{
	ll ans = 1, res = a;
	while (b) {
		if (b & 1) ans = ans*res%mod;
		res = res*res%mod;
		b >>= 1;
	}
	return ans%mod;
}
int main() {
	ll n;
	cin >> n;
	ll ans = n*ksm(2, n - 1) % mod;
	cout << ans << endl;
	return 0;
}