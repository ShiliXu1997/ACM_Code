//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月03日 星期四 20时59分13秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

struct tea {
	int id, sc, ab;

	bool operator<(const tea &another) const
	{
		if (sc == another.sc) return id < another.id;
		return sc > another.sc;
	}
};

int t, n, r, q;
tea te[MAXN], a[MAXN], b[MAXN];

void merge()
{
	int now = 0, i = 1, j = 1;
	while (now < 2 * n) {
		while (i <= n && (j > n || j <= n && a[i] < b[j])) te[++now] = a[i++];
		while (j <= n && (i > n || i <= n && b[j] < a[i])) te[++now] = b[j++];
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &r, &q);
		for (int i = 1; i <= 2 * n; i++) scanf("%d", &te[i].sc), te[i].id = i;
		for (int i = 1; i <= 2 * n; i++) scanf("%d", &te[i].ab);
		sort(te + 1, te + 1 + 2 * n);
		while (r--) {
			for (int i = 1, j = 1; i <= 2 * n - 1; i += 2, j++) {
				if (te[i].ab > te[i + 1].ab) te[i].sc++, a[j] = te[i], b[j] = te[i + 1];
				if (te[i].ab < te[i + 1].ab) te[i + 1].sc++, a[j] = te[i + 1], b[j] = te[i];
			}
			merge();
		}
		printf("%d\n", te[q].id);
	}
	return 0;
}
