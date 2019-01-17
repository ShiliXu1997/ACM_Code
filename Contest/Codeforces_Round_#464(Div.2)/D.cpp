//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月03日 星期二 16时28分38秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int fa[26];
char t[MAXN], s[MAXN];
vector<pair<int, int> > st;

int findfather(int x)
{
	return (fa[x] == x ? x : fa[x] = findfather(fa[x]));
}

int main()
{
	scanf("%d %s %s", &n, s, t);
	for (int i = 0; i < 26; i++) fa[i] = i;
	for (int i = 0; i < n; i++) {
		int p = findfather(s[i] - 'a'), q = findfather(t[i] - 'a');
		if (p != q) {
			if (p < q) swap(p, q);
			fa[q] = p;
			st.push_back(make_pair(q, p));
		}
	}
	printf("%d\n", st.size());
	for (int i = 0; i < st.size(); i++)
		printf("%c %c\n", st[i].first + 'a', st[i].second + 'a');
	return 0;
}
