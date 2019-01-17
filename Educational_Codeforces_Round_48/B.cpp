//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月03日 星期五 23时04分05秒
//******************************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;

int n, m, q;
string s, t;
char sc[MAXN], tc[MAXN], tmp[MAXN];
vector<int> pos;
int next_pos[MAXN];

void kmp(string s, string t)
{
	pos.clear();
	memset(next_pos, 0, sizeof(next_pos));
	int slen = s.length(), tlen = t.length();
	for (int i = 1; i < tlen; i++) {
		int j = i;
		while (j) {
			j = next_pos[j];
			if (t[j] == t[i]) {
				next_pos[i + 1] = j + 1;
				break;
			}
		}
	}
	for (int i = 0, j = 0; i < slen; i++) {
		if (j < tlen && s[i] == t[j])
			j++;
		else {
			while (j) {
				j = next_pos[j];
				if (s[i] == t[j]) {
					j++;
					break;
				}
			}
		}
		if (j == tlen) pos.push_back(i - tlen + 1);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	scanf("%s %s", sc, tc);
	t = string(tc);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		if (r - l + 1 < m) {
			printf("0\n");
			continue;
		}
		for (int i = l, j = 0; i <= r; i++) tmp[j++] = sc[i - 1];
		tmp[r - l + 1] = '\0';
		s = string(tmp);
		kmp(s, t);
		int ans = pos.size();
		printf("%d\n", ans);
	}
	return 0;
}
