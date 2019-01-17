//******************************************************************************
// File Name: POJ_3415.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 20 Oct 2018 10:53:13 AM CST
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

const int MAXN = 2e5 + 5;

int n, k, top;
char mes[MAXN];
int s[MAXN], sa[MAXN], rk[MAXN], height[MAXN], c[MAXN], x[MAXN], y[MAXN];
int st[MAXN], cnt[MAXN];

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

int main()
{
    while (scanf("%d", &k) == 1 && k) {
        scanf("%s", mes + 1);
        int len = strlen(mes + 1);
        n = 0;
        for (int i = 1; i <= len; i++) s[++n] = mes[i];
        s[++n] = (int)'#';
        int tag = n;
        scanf("%s", mes + 1);
        len = strlen(mes + 1);
        for (int i = 1; i <= len; i++) s[++n] = mes[i];
        get_sa();
        get_height();
        top = 0;
        ll ans = 0, sum = 0;
        for (int i = 2; i <= n; i++) {
            if (height[i] >= k) {
                int num = 0;
                while (top && st[top] > height[i] - k + 1) {
                    sum -= (ll)st[top] * cnt[top];
                    sum += (ll)(height[i] - k + 1) * cnt[top];
                    num += cnt[top];
                    top--;
                }
                st[++top] = height[i] - k + 1;
                if (sa[i - 1] > tag) {
                    sum += height[i] - k + 1;
                    cnt[top] = num + 1;
                }
                else
                    cnt[top] = num;
                if (sa[i] < tag) ans += sum;
            }
            else {
                top = 0;
                sum = 0;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (height[i] >= k) {
                int num = 0;
                while (top && st[top] > height[i] - k + 1) {
                    sum -= (ll)st[top] * cnt[top];
                    sum += (ll)(height[i] - k + 1) * cnt[top];
                    num += cnt[top];
                    top--;
                }
                st[++top] = height[i] - k + 1;
                if (sa[i - 1] < tag) {
                    sum += height[i] - k + 1;
                    cnt[top] = num + 1;
                }
                else
                    cnt[top] = num;
                if (sa[i] > tag) ans += sum;
            }
            else {
                top = 0;
                sum = 0;
            }
        }
        printf("%lld\n", ans);
    }
	return 0;
}
