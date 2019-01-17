//******************************************************************************
// File Name: POJ_1200.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 23 Sep 2018 07:39:20 PM CST
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

const int MAXN = 2e7;

int n, m;
char s[MAXN];
int id[300];
bool visited[MAXN];

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        scanf("%s", s);
        int len = strlen(s), cnt = 0;
        memset(id, 0, sizeof(id));
        for (int i = 0; i < len; i++)
            if (!id[s[i]]) id[s[i]] = cnt++;
        ull sum = 0, pow = 1;
        for (int i = 0; i < n; i++)
            sum = sum * m + id[s[i]], pow *= m;
        pow /= m;
        visited[sum] = true;
        int ans = 1;
        for (int i = n; i < len; i++) {
            sum -= id[s[i - n]] * pow;
            sum = sum * m + id[s[i]];
            if (visited[sum]) continue;
            visited[sum] = true;
            ans++;
        }
        printf("%d\n", ans);
    }
	return 0;
}
