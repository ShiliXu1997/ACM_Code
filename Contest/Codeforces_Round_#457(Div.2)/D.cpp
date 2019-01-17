//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月02日 星期五 16时28分44秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct string_trie {
	int data;
	string_trie *child[26];

	string_trie()
	{
		data = 0; 
		for (int i = 0; i < 26; i++) child[i] = NULL;
	}

	string_trie(string_trie *another)
	{
		data = another->data;
		for (int i = 0; i < 26; i++) child[i] = another->child[i];
	}
};

struct binary_trie {
	int data;
	binary_trie *child[2];

	binary_trie()
	{
		data = 0;
		child[0] = child[1] = NULL;
	}

	binary_trie(binary_trie *another)
	{
		data = another->data;
		child[0] = another->child[0];
		child[1] = another->child[1];
	}
};

string_trie *string_root[MAXN];
binary_trie *binary_root[MAXN];
int q;

void insert_string(int i, char *s, int x)
{
	string_trie *p = string_root[i];
	while (*s != '\0') {
		int id = *s - 'a';
		if (p->child[id])
			p->child[id] = new string_trie(p->child[id]);
		else
			p->child[id] = new string_trie();
		p = p->child[id];
		s++;
		if (*s == '\0') p->data = x;
	}
}

void insert_num(int i, int num, int x)
{
	binary_trie *p = binary_root[i];
	for (int j = 30; j >= 0; j--) {
		int id = (num >> j) & 1;
		if (p->child[id])
			p->child[id] = new binary_trie(p->child[id]);
		else
			p->child[id] = new binary_trie();
		p = p->child[id];
		p->data += x;
	}
}

int search(int i, char *s)
{
	string_trie *p = string_root[i];
	while (*s != '\0') {
		int id = *s - 'a';
		if (!p->child[id]) return 0;
		p = p->child[id];
		s++;
	}
	return p->data;
}

int query(int i, int num)
{
	binary_trie *p = binary_root[i];
	int ans = 0;
	for (int j = 30; j >= 0; j--) {
		int id = (num >> j) & 1;
		if (id && p->child[0]) ans += p->child[0]->data;
		p = p->child[id];
	}
	return ans;
}

int main()
{
	string_root[0] = new string_trie();
	binary_root[0] = new binary_trie();
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		char mes[6], str[16];
		int x;
		scanf("%s", mes);
		if (mes[0] == 's') {
			scanf("%s %d", str, &x);
			string_root[i] = new string_trie(string_root[i - 1]);
			binary_root[i] = new binary_trie(binary_root[i - 1]);
			int old = search(i, str);
			if (old != x) {
				insert_string(i, str, x);
				if (old) insert_num(i, old, -1);
				insert_num(i, x, 1);
			}
		}
		if (mes[0] == 'r') {
			scanf("%s", str);
			string_root[i] = new string_trie(string_root[i - 1]);
			binary_root[i] = new binary_trie(binary_root[i - 1]);
			int old = search(i, str);
			if (old) {
				insert_string(i, str, 0);
				insert_num(i, old, -1);
			}
		}
		if (mes[0] == 'q') {
			scanf("%s", str);
			string_root[i] = string_root[i - 1];
			binary_root[i] = binary_root[i - 1];
			int old = search(i, str);
			if (old)
				printf("%d\n", query(i, old));
			else
				printf("-1\n");
		}
		if (mes[0] == 'u') {
			scanf("%d", &x);
			string_root[i] = string_root[i - x - 1];
			binary_root[i] = binary_root[i - x - 1];
		}
		fflush(stdout);
	}
	return 0;
}

