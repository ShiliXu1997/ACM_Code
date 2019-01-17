//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 27 Sep 2018 07:56:05 PM CST
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

int n, m;
ll a[20], b[20];
set<ll> st, ans;
map<ll, vector<int> > mp;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll tot = 0;
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]), tot += b[i];
    sort(b + 1, b + 1 + m);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < (1 << m); i++) {
        ll w = 0;
        for (int j = 1; j <= m; j++) if (i & (1 << (j - 1))) w += b[j];
        mp[w].push_back(i);
    }
    for (map<ll, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it) {
        int sz = it->second.size();
        vector<int> &now = it->second;
        for (int i = 0; i < sz; i++)
            for (int j = i + 1; j < sz; j++) {
                bool flag = true;
                for (int k = 1; k <= m; k++)
                    if ((now[i] & (1 << (k - 1))) && (now[j] & (1 << (k - 1)))) flag = false;
                if (flag) st.insert(it->first);
            }
    }
    st.insert(0);
    for (set<ll>::iterator it = st.begin(); it != st.end(); ++it) {
        for (int i = 1; i <= n; i++) ans.insert(*it * 2 + a[i]);
    }
    for (set<ll>::iterator it = ans.begin(); it != ans.end(); ++it)
        printf("%lld\n", *it);
    return 0;
}
