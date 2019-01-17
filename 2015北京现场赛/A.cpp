//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 03 Nov 2018 12:42:54 PM CST
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

const int MAXN = 10005;

struct rec {
    int x, y, w, h;
};

int k, n, R;
ll sum;
rec r[MAXN];

bool check(int x, ll &diff, ll now)
{
    diff = 0;
    for (int i = 1; i <= n; i++) {
        int right = min(r[i].x + r[i].w, x);
        if (right >= r[i].x) diff += (ll)(right - r[i].x) * r[i].h;
    }
    diff = diff - (sum - diff);
    return diff >= 0 && diff <= now;
}

int main()
{
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &R);
        scanf("%d", &n);
        sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &r[i].x, &r[i].y, &r[i].w, &r[i].h);
            sum += (ll)r[i].w * r[i].h;
        }
        ll now = sum;
        int l = 0, r = R, ans = R;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll diff;
            if (check(mid, diff, now))
                ans = mid, r = mid - 1, now = diff;
            else
                l = mid + 1;
        }
        l = ans, r = R;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll diff;
            if (check(mid, diff, now))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
	return 0;
}
