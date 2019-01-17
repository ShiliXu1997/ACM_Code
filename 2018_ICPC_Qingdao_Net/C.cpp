//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 16 Sep 2018 01:03:45 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5;

int t, n;
bool dp[MAXN][300];
string mes[MAXN];
int v[MAXN], k[MAXN];

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> mes[i];
            if (mes[i][1] == 'd') cin >> v[i];
            if (mes[i][1] == 'e') cin >> v[i] >> k[i];
            if (mes[i][1] == 'n') cin >> v[i] >> k[i];
            if (mes[i][1] == 'l') cin >> v[i] >> k[i];
            if (mes[i][1] == 'g') cin >> v[i] >> k[i];
        }
        memset(dp, false, sizeof(dp));
        bool ans = true;
        int p = 1, now = 0;
        while (true) {
            dp[p][now] = true;
            int nxt = p + 1;
            if (mes[p][1] == 'd') {
                now = (now + v[p]) % 256;
            }
            else
            if (mes[p][1] == 'e') {
                if (now == v[p]) nxt = k[p];
            }
            else
            if (mes[p][1] == 'n') {
                if (now != v[p]) nxt = k[p];
            }
            else
            if (mes[p][1] == 'l') {
                if (now < v[p]) nxt = k[p];
            }
            else
            if (mes[p][1] == 'g') {
                if (now > v[p]) nxt = k[p];
            }
            if (nxt > n) break;
            if (dp[nxt][now]) {
                ans = false;
                break;
            }
            else
                p = nxt;
        }
        cout << (ans ? "Yes" : "No") << endl;
    }
	return 0;
}
