//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Mon 22 Oct 2018 10:35:26 PM CST
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

int main()
{
    ll a, b, sum = 0;
    scanf("%lld %lld", &a, &b);
    ll now = 1;
    while (sum + now <= a + b) {
        sum += now;
        now++;
    }
    now--;
    vector<ll> ans_a, ans_b;
    for (ll i = now; i >= 1; i--) {
        if (i <= a)
            ans_a.push_back(i), a -= i;
        else
            ans_b.push_back(i), b -= i;
    }
    printf("%d\n", (int)ans_a.size());
    for (auto i: ans_a) printf("%lld ", i);
    puts("");
    printf("%d\n", (int)ans_b.size());
    for (auto i: ans_b) printf("%lld ", i);
	return 0;
}
