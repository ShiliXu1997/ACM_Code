//******************************************************************************
// File Name: SPOJ_SUBST1.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Fri 19 Oct 2018 01:22:23 PM CST
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

const int MAXN = 5e4 + 5;

int t, n;
char s[MAXN];
int sa[MAXN], rk[MAXN], height[MAXN], x[MAXN], y[MAXN], c[MAXN];

void get_sa()
{
    int m = 255;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i >= 1; i--) sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int num = 0;
        for (int i = n - k + 1; i <= n; i++) y[++num] = i;
        for (int i = 1; i <= n; i++) if (sa[i] > k) y[++num] = sa[i] - k;
        for (int i = 1; i <= m; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) c[x[i]]++;
        for (int i = 2; i <= m; i++) c[i] += c[i - 1];
        for (int i = n; i >= 1; i--) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
        swap(x, y);
        x[sa[1]] = num = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
        if (num == n) break;
        m = num;
    }
}

void get_height()
{
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (rk[i] == 1) continue;
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (j + k <= n && i + k <= n && s[j + k] == s[i + k]) k++;
        height[rk[i]] = k;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        get_sa();
        get_height();
        ll ans = (ll)n * (n + 1) / 2;
        for (int i = 2; i <= n; i++) ans -= height[i];
        printf("%lld\n", ans);
    }
	return 0;
}
