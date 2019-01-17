//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 11:01:48 PM CST
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
typedef pair<int, int> pii;
#define x first
#define y second

const int MAXN = 2e5 + 5;

int n;
ll t;
int a[MAXN];
queue<pii> q;

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %lld", &n, &t);
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum += a[i], q.push(make_pair(a[i], i));
    ans += (ll)n * (t / sum);
    t %= sum;
    int last = 0;
    n = 0;
    while (!q.empty()) {
        pii now = q.front(); q.pop();
        if (last == now.y) {
            ans += (ll)n * (t / sum + 1);
            t %= sum;
            last = 0;
        }
        if (t >= now.x) {
            if (last == 0) {
                last = now.y;
                n = 0;
                sum = 0;
            }
            n++;
            sum += now.x;
            t -= now.x;
            q.push(now);
        }
    }
    printf("%lld\n", ans);
	return 0;
}
