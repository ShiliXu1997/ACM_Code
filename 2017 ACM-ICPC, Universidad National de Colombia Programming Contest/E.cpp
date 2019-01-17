//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月21日 星期六 15时11分08秒
//************************************************************************

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n;
string a, t;
char buff[MAXN];
int next_val[MAXN];

void get_next(string t)
{
	memset(next_val, 0, sizeof(next_val));
	int len = t.length();
	for (int i = 1; i < len; i++) {
		int j = i;
		while (j > 0) {
			j = next_val[j];
			if (t[j] == t[i]) {
				next_val[i + 1] = j + 1;
				break;
			}
		}
	}
}

int kmp(string s, string t)
{
	get_next(t);
	int cnt = 0;
	int slen = s.length(), tlen = t.length();
	for (int i = 0, j = 0; i < slen; i++) {
		if (j < tlen && s[i] == t[j])
			j++;
		else {
			while (j > 0) {
				j = next_val[j];
				if (s[i] == t[j]) {
					j++;
					break;
				}
			}
		}
		if (j == tlen) cnt++;
	}
	return cnt;
}

int main()
{
	cin.getline(buff, MAXN - 4); a = string(buff);
	cin.getline(buff, MAXN - 4); t = string(buff);
	cin >> n;
	if (kmp(a, t.substr(0, 1)) < n) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	int alen = a.length();
	int l = 1, r = t.length();
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		string str = t.substr(0, mid);
		if (kmp(a, str) >= n)
			l = mid;
		else
			r = mid - 1;
	}
	if (kmp(a, t.substr(0, r)) >= n)
		cout << t.substr(0, r);
	else
		cout << t.substr(0, l);
	return 0;
}
