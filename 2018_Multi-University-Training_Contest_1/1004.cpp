//******************************************************************************
// File Name: 1004.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月25日 星期三 10时43分44秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int t, n, m;
int last[MAXN], ans[MAXN];
set<int> st;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		st.clear();
		for (int i = 1; i <= n; i++) {
			last[i] = i;
			st.insert(i);
		}
		while (m--) {
			int l, r;
			scanf("%d %d", &l, &r);
			last[l] = max(last[l], r);
		}
		int l = 1, r = 0;
		for (int i = 1; i <= n; i++) {
			if (last[i] <= r) continue;
			while (l < i) st.insert(ans[l++]);
			while (r < last[i]) ans[++r] = *st.begin(), st.erase(ans[r]);
		}
		for (int i = 1; i < n; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	return 0;
}
