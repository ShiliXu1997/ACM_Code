//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Tue 02 Oct 2018 12:10:26 PM CST
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

const int MAXN = 25;

int n, m;
char s[MAXN];
int cnt[MAXN];
set<pair<int, char> > ans;

int main()
{
    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        memset(cnt, 0, sizeof(cnt));
        ans.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%s", s);
            for (int j = 0; j < m; j++) cnt[s[j] - 'A']++;
        }
        if (cnt['A' - 'A']) ans.insert(make_pair(-cnt['A' - 'A'], 'A'));
        if (cnt['C' - 'A']) ans.insert(make_pair(-cnt['C' - 'A'], 'C'));
        if (cnt['D' - 'A']) ans.insert(make_pair(-cnt['D' - 'A'], 'D'));
        if (cnt['E' - 'A']) ans.insert(make_pair(-cnt['E' - 'A'], 'E'));
        if (cnt['G' - 'A']) ans.insert(make_pair(-cnt['G' - 'A'], 'G'));
        for (set<pair<int, char> >::iterator it = ans.begin(); it != ans.end(); ++it) {
            if (it != ans.begin()) printf(" %c %d", it->second, -(it->first));
            else printf("%c %d", it->second, -(it->first));
        }
        puts("");
    }
	return 0;
}
