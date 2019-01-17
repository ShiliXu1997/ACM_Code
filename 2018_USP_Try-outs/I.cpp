//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 21 Oct 2018 01:10:57 PM CST
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

int n, k;

void hanoi(int x, char a, char b, char c)
{
    if (x == 1) {
        printf("%c %c\n", a, c);
        return;
    }
    hanoi(x - 1, a, c, b);
    printf("%c %c\n", a, c);
    hanoi(x - 1, b, a, c);
}

int main()
{
    scanf("%d %d", &n, &k);
    int diff = k - ((1 << n) - 1);
    if (diff == 0 || diff >= 2) {
        printf("Y\n");
        if (diff >= 2) {
            printf("A B\n");
            diff -= 2;
            char now = 'B';
            while (diff) {
                printf("%c %c\n", now, now == 'B' ? 'C' : 'B');
                now = now == 'B' ? 'C' : 'B';
                diff--;
            }
            printf("%c A\n", now);
        }
        hanoi(n, 'A', 'B', 'C');
    }
    else
        printf("N\n");
	return 0;
}
