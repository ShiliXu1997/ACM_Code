//******************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 03 Nov 2018 12:16:00 PM CST
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

int n;

int main()
{
    while (scanf("%d", &n) == 1) {
        int ans = 0;
        char mes[2];
        while (n--) {
            scanf("%s", mes);
            if (mes[0] == 'S')
                ans++;
            else {
                int x;
                scanf("%d", &x);
                if (x == 1) ans++;
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}
