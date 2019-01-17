//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Tue 06 Nov 2018 03:40:32 PM CST
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
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define x first
#define y second

const int MAXN = 115, MAXM = 1e6 + 5, INF = 0x3f3f3f3f;

int cnt;
char s1[MAXN], s2[MAXN];
int num[MAXN], dp[MAXM], id[MAXM], change[7], p[7];
queue<int> q;

void bfs()
{
    id[cnt = 1] = 123456;
    memset(dp, 0x3f, sizeof(dp));
    q.push(123456);
    dp[123456] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                if (i != j) {
                    int now = 0;
                    for (int k = 1; k <= 6; k++) {
                        now *= 10;
                        int r = u % p[k - 1] / p[k];
                        if (r == i)
                            now += j;
                        else
                            now += r;
                    }
                    if (dp[u] + 1 < dp[now]) {
                        dp[now] = dp[u] + 1;
                        id[++cnt] = now;
                        q.push(now);
                    }
                }
    }
}

int main()
{
    p[0] = 1e6;
    for (int i = 1; i <= 6; i++) p[i] = p[i - 1] / 10;
    bfs();
    while (scanf("%s %s", s1, s2) == 2) {
        int len = strlen(s1), ans = INF;
        for (int i = 1; i <= cnt; i++) {
            int now = id[i], tot = 0;
            for (int j = 1; j <= 6; j++)
                change[j] = now % p[j - 1] / p[j];
            for (int j = 0; j < len; j++) {
                num[j] = s2[j] & 15;
                num[j] = change[num[j]];
                if ((s1[j] & 15) != num[j]) tot++;
            }
            ans = min(ans, dp[now] + tot);
        }
        printf("%d\n", ans);
    }
	return 0;
}
