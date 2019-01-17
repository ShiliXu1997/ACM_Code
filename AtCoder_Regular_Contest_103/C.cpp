//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 29 Sep 2018 08:03:59 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 5;

int n;
int aa[MAXN], a[MAXN], v[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int ans = 0x3f3f3f3f, x = 0, y = 0, p = 0, q = 0;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i += 2) a[v[i]]++;
    for (int i = 1; i <= 1e5; i++)
        if (a[i] > a[x]) {
            y = x;
            x = i;
        }
        else{
            if (a[i] > a[y]) y = i;
        }
    memset(aa, 0, sizeof(aa));
    for (int i = 2; i <= n; i += 2) aa[v[i]]++;
    for (int i = 1; i <= 1e5; i++)
        if (aa[i] > aa[p]) {
            q = p;
            p = i;
        }
        else {
            if (aa[i] > aa[q]) q = i;
        }
    if (x != p) ans = min(ans, n / 2 - a[x] + n / 2 - aa[p]);
    if (x != q) ans = min(ans, n / 2 - a[x] + n / 2 - aa[q]);
    if (y != p) ans = min(ans, n / 2 - a[y] + n / 2 - aa[p]);
    if (y != q) ans = min(ans, n / 2 - a[y] + n / 2 - aa[q]);
    if (ans == 0x3f3f3f3f) ans = min(n / 2 - a[x], n / 2 - aa[p]);
    printf("%d\n", ans);
	return 0;
}
