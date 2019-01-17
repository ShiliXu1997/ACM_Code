//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月06日 星期五 00时33分53秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 105;

int n;
ll d;
ll a[MAXN];
set<ll> st;

int main()
{
	scanf("%d %lld", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		ll left = a[i] - d, right = a[i] + d;
		if (i > 1) {
			if (llabs(left - a[i - 1]) >= d) st.insert(left);
		}
		else
			st.insert(left);
		if (i < n) {
			if (llabs(right - a[i + 1]) >= d) st.insert(right);
		}
		else
			st.insert(right);
	}
	int ans = st.size(); 
	printf("%d\n", ans);

	return 0;
}
