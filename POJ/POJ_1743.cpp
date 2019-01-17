//******************************************************************************
// File Name: POJ_1743.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 18 Oct 2018 04:16:22 PM CST
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

const int MAXN = 20005;

int n;
int s[MAXN], sa[MAXN], rk[MAXN], height[MAXN], c[MAXN], x[MAXN], y[MAXN];

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
        while (j + k <= n && i + k <= n && s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}

bool check(int xx)
{
    int mn = sa[1], mx = sa[1];
    for (int i = 2; i <= n; i++) {
        if (height[i] < xx)
            mn = mx = sa[i];
        else {
            if (sa[i] < mn) mn = sa[i];
            if (sa[i] > mx) mx = sa[i];
            if (mx - mn > xx) return true;
        }
    }
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
        for (int i = n; i >= 1; i--) s[i] = s[i] - s[i - 1] + 88;
        get_sa();
        get_height();
        int l = 0, r = n >> 1, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        if (ans + 1 >= 5)
            printf("%d\n", ans + 1);
        else
            printf("0\n");
    }
	return 0;
}
