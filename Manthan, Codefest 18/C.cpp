//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 23时18分06秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

int n;
char a[MAXN], c[MAXN];
bool done[MAXN];

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%s", c + 1);
	int ans = 0;
	memset(done, false, sizeof(done));
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] != c[i] && a[i + 1] != c[i + 1] && a[i] != a[i + 1] && !done[i] && !done[i + 1]) {
			done[i] = done[i + 1] = true;
			swap(a[i], a[i + 1]);
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) if (a[i] != c[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
