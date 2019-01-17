//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 12:26:17 PM CST
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

const int MAXN = 1e5 + 5, MAXM = 1e6 + 5;

int t, n;
int a[MAXN], cnt[MAXM];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            for (int j = 2; (ll)j * j <= a[i]; j++) {
                if (a[i] % j == 0) cnt[j]++;
                while (a[i] % j == 0) a[i] /= j;
            }
            if (a[i] > 1) cnt[a[i]]++;
        }
        int ans = 0;
        for (int i = 2; i < MAXM; i++)
            ans += cnt[i] / 3 + (cnt[i] % 3 > 0);
        printf("%d\n", ans);
    }
	return 0;
}
