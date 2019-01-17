//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 02:12:17 PM CST
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

const int MAXN = 102;

int t, n, m, k;
int c[MAXN][MAXN], s[MAXN][MAXN];

int lowbit(int x)
{
    return x & -x;
}

void modify(int x, int y, int num)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j)) c[i][j] += num;
}

int sum(int x, int y)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j)) ans += c[i][j];
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) c[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int x;
                scanf("%d", &x);
                if (x) modify(i, j, 1);
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) s[i][j] = sum(i, j);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int p = i; p <= n; p++) {
                    int l = j - 1, r = m + 1;
                    while (l + 1 < r) {
                        int mid = (l + r) >> 1, q = mid;
                        int cnt = s[p][q] - s[p][j - 1] - s[i - 1][q] + s[i - 1][j - 1];
                        if (cnt <= k)
                            l = mid;
                        else
                            r = mid;
                    }
                    if (l >= j) ans = max(ans, (p - i + 1) * (l - j + 1));
                }
        printf("%d\n", ans);
    }
	return 0;
}
