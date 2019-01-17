//************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月29日 星期四 19时18分18秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

const int MAXN = 105;

int n;
char s[MAXN], t[MAXN], p[MAXN];
int nextval[MAXN], nxtval[MAXN];
int val[MAXN], vl[MAXN];

void getnext(const char *t, int cur)
{
    if (cur == 0) memset(nextval, 0, sizeof(nextval)), nextval[0] = -1;
    if (cur == 1) memset(nxtval, 0, sizeof(nxtval)), nxtval[0] = -1;
    if (cur == 2) memset(val, 0, sizeof(val)), val[0] = -1;
    if (cur == 3) memset(vl, 0, sizeof(vl)), vl[0] = -1;
    int len = strlen(t), k = -1, j = 0;
    while (j < len) {
        if (k == -1 || t[k] == t[j]) {
            k++; j++;
            int w = k;
            if (cur == 0){
				while (w != -1 && t[w] == t[j]) w = nextval[w];
				nextval[j] = w;
			}
            if (cur == 1){
				while (w != -1 && t[w] == t[j]) w = nxtval[w];
				nxtval[j] = w;
			}
            if (cur == 2){
				while (w != -1 && t[w] == t[j]) w = val[w];
				val[j] = w;
			}
            if (cur == 3){
				while (w != -1 && t[w] == t[j]) w = vl[w];
				vl[j] = w;
			}
        }
        else {
			if (cur == 0)
				k = nextval[k];
			if (cur == 1) 
				k = nxtval[k];
			if (cur == 2)
				k = val[k];
			if (cur == 3)
				k = vl[k];
		}
    }
}

int kmp(const char *s, const char *t, int cur)
{
    int slen = strlen(s), tlen = strlen(t);
    int i = 0, j = 0;
    while (i < slen && j < tlen) {
        if (j == -1 || s[i] == t[j]) {
            i++; j++;
        }
        else {
            if (cur == 0) j = nextval[j];
            if (cur == 1) j = nxtval[j];
            if (cur == 2) j = val[j];
            if (cur == 3) j = vl[j];
		}
    }
    if (j == tlen)
        return i - j;
    else
        return -1;
}

int main()
{
	getnext("white", 0);
	getnext("gold", 1);
	getnext("black", 2);
	getnext("blue", 3);
	scanf("%d", &n);
	getchar();
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		cin.getline(s, 105);
		if (kmp(s, "white", 0) != -1 && kmp(s, "gold", 1) != -1
			&& kmp(s, "black", 2) != -1 && kmp(s, "blue", 3) != -1) continue;
		if (kmp(s, "white", 0) != -1 && kmp(s, "gold", 1) != -1) cnt1++;
		if (kmp(s, "black", 2) != -1 && kmp(s, "blue", 3) != -1) cnt2++;
	}
	printf("%.5f\n%.5f\n%.5f\n", (double)cnt2 / n * 100, (double)cnt1 / n * 100, (double)(n - cnt1 - cnt2) / n * 100);
	return 0;
}
