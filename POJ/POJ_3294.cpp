//******************************************************************************
// File Name: POJ_3294.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Fri 19 Oct 2018 10:12:12 PM CST
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

const int MAXN = 110005;

int n, t, sz;
char mes[1005];
int s[MAXN], sa[MAXN], rk[MAXN], height[MAXN], c[MAXN], x[MAXN], y[MAXN], ans[1005], pos[105];
bool done[105];

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

bool check(int len)
{
    int cnt = 0, now = 0;
    memset(done, false, sizeof(done));
    for (int i = 2; i <= n; i++) {
        if (height[i] >= len) {
            for (int j = 1; j <= t; j++) {
                if (pos[j - 1] < sa[i - 1] && sa[i - 1] < pos[j]) cnt += !(done[j]), done[j] = true;
                if (pos[j - 1] < sa[i] && sa[i] < pos[j]) cnt += !(done[j]), done[j] = true;
            }
        }
        else {
            if (cnt > t / 2) ans[++now] = sa[i - 1];
            cnt = 0;
            memset(done, false, sizeof(done));
        }
    }
    if (cnt > t / 2) ans[++now] = sa[n];
    if (now > 0) {
        sz = now;
        return true;
    }
    return false;
}

int main()
{
    while (scanf("%d", &t) == 1 && t) {
        n = 0;
        pos[0] = 0;
        for (int i = 1; i <= t; i++) {
            scanf("%s", mes);
            int len = strlen(mes);
            for (int i = 1; i <= len; i++) s[n + i] = (int)mes[i - 1];
            n += len;
            s[n + 1] = 130 + i;
            pos[i] = n + 1;
            n++;
        }
        get_sa();
        get_height();
        int l = 1, r = n, len = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                len = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        if (!len)
            printf("?\n\n");
        else {
            for (int i = 1; i <= sz; i++) {
                for (int j = 0; j < len; j++) printf("%c", s[ans[i] + j]);
                puts("");
            }
            puts("");
        }
    }
	return 0;
}
