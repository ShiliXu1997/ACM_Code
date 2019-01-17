//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月27日 星期五 15时56分07秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 6;

struct node {
	char op;
	int val, ch[2], fa;
};

int n;
int dp[MAXN][2];
node nd[MAXN];

void build(int rt)
{
	node &now = nd[rt];
	if (now.op == '=') return;
	if (now.op == '&' || now.op == '|' || now.op == '^') {
		build(now.ch[0]);
		build(now.ch[1]);
		if (now.op == '&') now.val = nd[now.ch[0]].val & nd[now.ch[1]].val;
		if (now.op == '|') now.val = nd[now.ch[0]].val | nd[now.ch[1]].val;
		if (now.op == '^') now.val = nd[now.ch[0]].val ^ nd[now.ch[1]].val;
	}
	else {
		build(now.ch[0]);
		now.val = nd[now.ch[0]].val ^ 1;
	}
}

int dfs(int rt, int num)
{
	if (dp[rt][num] != -1) return dp[rt][num];
	if (rt == 1) return num;
	node &f = nd[nd[rt].fa];
	if (f.op == '&' || f.op == '|' || f.op == '^') {
		int w = nd[f.ch[f.ch[0] == rt]].val;
		if (f.op == '&') return dp[rt][num] = dfs(nd[rt].fa, w & num);
		if (f.op == '|') return dp[rt][num] = dfs(nd[rt].fa, w | num);
		if (f.op == '^') return dp[rt][num] = dfs(nd[rt].fa, w ^ num);
	}
	else {
		return dp[rt][num] = dfs(nd[rt].fa, num ^ 1);
	}
}

int main()
{
	scanf("%d", &n);
	char mes[5];
	for (int i = 1; i <= n; i++) {
		nd[i].ch[0] = nd[i].ch[1] = 0;
		scanf("%s", mes);
		if (mes[0] == 'A') {
			nd[i].op = '&';
			int a, b;
			scanf("%d %d", &a, &b);
			nd[a].fa = nd[b].fa = i;
			nd[i].ch[0] = a;
			nd[i].ch[1] = b;
		}
		if (mes[0] == 'O') {
			nd[i].op = '|';
			int a, b;
			scanf("%d %d", &a, &b);
			nd[a].fa = nd[b].fa = i;
			nd[i].ch[0] = a;
			nd[i].ch[1] = b;
		}
		if (mes[0] == 'X') {
			nd[i].op = '^';
			int a, b;
			scanf("%d %d", &a, &b);
			nd[a].fa = nd[b].fa = i;
			nd[i].ch[0] = a;
			nd[i].ch[1] = b;
		}
		if (mes[0] == 'N') {
			nd[i].op = '!';
			int a;
			scanf("%d", &a);
			nd[a].fa = i;
			nd[i].ch[0] = a;
		}
		if (mes[0] == 'I') {
			nd[i].op = '=';
			int a;
			scanf("%d", &a);
			nd[i].val = a;
		}
	}
	build(1);
	memset(dp, 0xff, sizeof(dp));
	for (int i = 1; i <= n; i++) dp[i][nd[i].val] = nd[1].val;
	for (int i = 1; i <= n; i++) {
		node &now = nd[i];
		if (now.op == '=') printf("%d", dfs(i, now.val ^ 1));
	}
	return 0;
}
