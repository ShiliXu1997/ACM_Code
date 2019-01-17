//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 11:47:31 PM CST
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

const int MAXN = 2e5 + 5;

int n, edx, edy;
int cnt[5][MAXN];
char s[MAXN];

bool check(int len)
{
    bool flag = false;
    for (int i = 1; i <= n - len + 1 && !flag; i++) {
        int j = i + len - 1;
        int nowy = cnt[1][i - 1] - cnt[2][i - 1] + (cnt[1][n] - cnt[1][j]) - (cnt[2][n] - cnt[2][j]);
        int nowx = cnt[4][i - 1] - cnt[3][i - 1] + (cnt[4][n] - cnt[4][j]) - (cnt[3][n] - cnt[3][j]);
        int fuck = abs(nowx - edx) + abs(nowy - edy);
        if (len >= fuck) flag = true;
    }
    return flag;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%d %d", &edx, &edy);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') cnt[1][i]++; cnt[1][i] += cnt[1][i - 1];
        if (s[i] == 'D') cnt[2][i]++; cnt[2][i] += cnt[2][i - 1];
        if (s[i] == 'L') cnt[3][i]++; cnt[3][i] += cnt[3][i - 1];
        if (s[i] == 'R') cnt[4][i]++; cnt[4][i] += cnt[4][i - 1];
    }
    int fuck = abs(edx) + abs(edy);
    if (n < fuck || (n - fuck) & 1) {
        printf("-1\n");
        return 0;
    }
    int l = 0, r = n, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
	return 0;
}
