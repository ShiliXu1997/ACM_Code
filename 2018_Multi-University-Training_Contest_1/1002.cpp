//******************************************************************************
// File Name: 1002.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月24日 星期二 15时26分12秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

struct paigu {
	int len, left, right;

	bool operator<(const paigu &another) const
	{
		if (left <= right && another.left > another.right) return false;
		if (left > right && another.left <= another.right) return true;
		if (left <= right && another.left <= another.right) return left > another.left;
		if (left >= right && another.left >= another.right) return right < another.right;
	}
};

int t, n;
char str[MAXN];
paigu p[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			p[i].len = p[i].left = p[i].right = 0;
			scanf("%s", str);
			int len = strlen(str);
			for (int j = 0; j < len; j++) {
				if (str[j] == '(')
					p[i].left++;
				else {
					if (p[i].left > 0)
						p[i].left--, p[i].len += 2;
					else
						p[i].right++;
				}
			}
		}
		sort(p + 1, p + 1 + n);
		int ans = 0, now = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i].right > now) p[i].right = now;
			now -= p[i].right;
			now += p[i].left;
			ans += (2 * p[i].right) + p[i].len;
		}
		printf("%d\n", ans);
	}
	return 0;
}
