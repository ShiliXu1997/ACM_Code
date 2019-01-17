//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 06 Oct 2018 12:54:22 PM CST
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

struct fuck {
    int tp;
    vector<ll> p;
};

int n;
fuck f[MAXN];
set<ll> st[2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int s;
        scanf("%d %d", &f[i].tp, &s);
        while (s--) {
            ll x;
            scanf("%lld", &x);
            f[i].p.push_back(x);
        }
        sort(f[i].p.begin(), f[i].p.end());
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (f[i].tp == 1) {
            if (!flag) {
                flag = true;
                for (int j = 0; j < (int)f[i].p.size(); j++)
                    st[0].insert(f[i].p[j]);
            }
            else {
                for (ll miao: st[0]) {
                    int pos = lower_bound(f[i].p.begin(), f[i].p.end(), miao) - f[i].p.begin();
                    if (pos == (int)f[i].p.size() || f[i].p[pos] != miao) st[1].insert(miao);
                }
            }
        }
        else {
            for (int j = 0; j < (int)f[i].p.size(); j++)
                st[1].insert(f[i].p[j]);
        }
    }
    if (!flag)
        printf("%lld\n", (ll)1e18 - st[1].size());
    else {
        ll ans = 0;
        for (ll miao: st[0])
            if (!st[1].count(miao)) ans++;
        printf("%lld\n", ans);
    }
	return 0;
}
