//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月29日 星期日 21时57分14秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m, l, e, q;
ll v;
int sta[MAXN], ele[MAXN];

int main()
{
	scanf("%d %d %d %d %lld", &n, &m, &l, &e, &v);
	for (int i = 1; i <= l; i++) scanf("%d", &sta[i]);
	for (int i = 1; i <= e; i++) scanf("%d", &ele[i]);
	scanf("%d", &q);
	while (q--) {
		ll x_1, y_1, x_2, y_2;
		scanf("%lld %lld %lld %lld", &x_1, &y_1, &x_2, &y_2);
		if (y_1 > y_2) swap(y_1, y_2);
		if (x_1 == x_2) {
			printf("%lld\n", (y_2 - y_1));
			continue;
		}
		ll ans = 0;
		int sta_left = (int)(lower_bound(sta + 1, sta + 1 + l, y_1) - sta);
		int sta_right = (int)(lower_bound(sta + 1, sta + 1 + l, y_2) - sta);
		int ele_left = (int)(lower_bound(ele + 1, ele + 1 + e, y_1) - ele);
		int ele_right = (int)(lower_bound(ele + 1, ele + 1 + e, y_2) - ele);
		if (ele_right - ele_left)
			ans += (abs(x_1 - x_2) / v) + (ll)(abs(x_1 - x_2) % v != 0);
		if (!ans) {
			ll st_1 = INF, st_2 = INF, st_3 = INF, el_1 = INF, el_2 = INF;
			if (sta_left > 1) st_1 = (y_1 - sta[sta_left - 1]) * 2 + (ll)abs(x_1 - x_2);
			if (ele_left > 1) el_1 = (y_1 - ele[ele_left - 1]) * 2 + (ll)abs(x_1 - x_2) / v + (ll)(abs(x_1 - x_2) % v != 0);
			if (sta_right <= l) st_2 = (sta[sta_right] - y_2) * 2 + (ll)abs(x_1 - x_2);
			if (ele_right <= e) el_2 = (ele[ele_right] - y_2) * 2 + (ll)abs(x_1 - x_2) / v + (ll)(abs(x_1 - x_2) % v != 0);
			if (sta_right - sta_left) st_3 = (ll)abs(x_1 - x_2);
			ll add = min(min(st_1, st_2), min(el_1, el_2));
			add = min(add, st_3);
			ans += add;
		}
		ans += (y_2 - y_1);
		printf("%lld\n", ans);
	}
	return 0;
}
