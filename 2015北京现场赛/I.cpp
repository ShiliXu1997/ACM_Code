//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 03 Nov 2018 03:36:39 PM CST
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

int n;
int dir[] = {0, -1, 0, 1, -1, 0, -1, 0}, dt[] = {1, 2, 3, 0};

int main()
{
    while (scanf("%d", &n) == 1) {
        int w = n, h = n + 1;
        if (w % 2 == 0) w /= 2;
        if (h % 2 == 0) h /= 2;
        if (w > h) swap(w, h);
        if (n == 1) {
            printf("1 1\n");
            printf("1 1\n");
            continue;
        }
        if (n == 2) {
            printf("1 3\n");
            printf("1 1\n");
            printf("1 2 1 3\n");
            continue;
        }
        printf("%d %d\n", h, w);
        int xx = 1, yy = 1;
        int _xx = h, _yy = w;
        if (n % 2 == 0) xx += 2;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                int cnt = 1, t = 0, x = xx, y = yy;
                while (cnt < i) {
                    printf("%d %d ", x, y);
                    x += dir[t];
                    y += dir[t + 4];
                    t = dt[t];
                    cnt++;
                }
                xx += 2, yy += 1;
                printf("%d %d\n", x, y);
            }
            else {
                for (int j = 1; j <= i / 2; j++) printf("%d %d ", _xx - 1, _yy - j + 1);
                for (int j = i / 2; j > 1; j--) printf("%d %d ", _xx - 2, _yy - j + 1);
                printf("%d %d\n", _xx - 2, _yy);
                _xx -= 2;
            }
        }
    }
	return 0;
}
