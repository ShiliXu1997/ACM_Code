//******************************************************************************
// File Name: HDU_4135.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月03日 星期五 14时06分01秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int t, n;
ll a, b;
vector<int> p;

void get_factors(int n)
{
	p.clear();
	for (int i = 2; (ll)i * i <= n; i++) {
		if (n % i == 0) p.push_back(i);
		while (n % i == 0) n /= i;
	}
	if (n > 1) p.push_back(n);
}

vector<int> multiply(int bg, int sz)
{
	vector<int> ans;
	if (sz == 1) {
		ans.push_back(p[bg - 1]);
		return ans;
	}
	for (int i = bg + 1; i <= p.size() + 2 - sz; i++) {
		vector<int> v = multiply(i, sz - 1);
		for (int j = 0; j < v.size(); j++) ans.push_back(p[bg - 1] * v[j]);
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		scanf("%lld %lld %d", &a, &b, &n);
		get_factors(n);
		ll ans = 0;
		for (int i = 1; i <= p.size(); i++) {
			for (int j = 1; j <= p.size() + 1 - i; j++) {
				vector<int> v = multiply(j, i);
				for (int k = 0; k < v.size(); k++)
					ans	+= (ll)(i & 1 ? 1 : -1) * (b / v[k] - a / v[k] + (a % v[k] == 0));
			}
		}
		printf("Case #%d: %lld\n", kase, (b - a + 1) - ans);
	}
	return 0;
}
