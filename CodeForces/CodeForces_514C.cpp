//******************************************************************************
// File Name: CodeForces_514C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Tue 25 Sep 2018 03:56:57 PM CST
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

const int MAXN = 6e5 + 5, BASE = 131;
const ll MOD = 1e11 + 7;

int n, m;
char s[MAXN];
set<ll> st;

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        ll v = 0;
        for (int j = 0; j < len; j++) v = (v * BASE + s[j] - 'a' + 1) % MOD;
        st.insert(v);
    }
    while (m--) {
        scanf("%s", s);
        int len = strlen(s);
        ll v = 0, tmp = 1;
        for (int j = 0; j < len; j++) v = (v * BASE + s[j] - 'a' + 1) % MOD;
        bool flag = false;
        for (int j = len - 1; j >= 0 && !flag; j--) {
            if (s[j] == 'a' && (st.count((v + tmp) % MOD) || st.count((v + tmp * 2) % MOD)))
                flag = true;
            if (s[j] == 'b' && (st.count((v + tmp) % MOD) || st.count(((v - tmp) % MOD + MOD) % MOD)))
                flag = true;
            if (s[j] == 'c' && (st.count(((v - tmp) % MOD + MOD) % MOD) || st.count(((v - tmp * 2) % MOD + MOD) % MOD)))
                flag = true;
            tmp *= BASE;
            tmp %= MOD;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
	return 0;
}
