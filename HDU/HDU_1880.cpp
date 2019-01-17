//******************************************************************************
// File Name: HDU_1880.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Mon 24 Sep 2018 07:45:06 PM CST
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

const int MAXN = 1e5 + 5, BASE = 131;

struct hs {
    ull value;
    int id;

    hs() {}
    hs(ull u, int v) : value(u), id(v) {}

    bool operator<(const hs &another) const
    {
        return value < another.value;
    }
};

int n;
char s[120];
char magic[MAXN][120], say[MAXN][120];
hs mm[MAXN], ss[MAXN];

ull get_hash(char *str)
{
    ull ans = 0;
    while (*str && *str != '\n' && *str != '\r') {
        ans = ans * BASE + *str;
        str++;
    }
    return ans;
}

int main()
{
    int cnt = 0;
    while (scanf("%s", magic[++cnt]) == 1 && strcmp(magic[cnt], "@END@")) {
        getchar();
        mm[cnt].value = get_hash(magic[cnt]);
        mm[cnt].id = cnt;
        fgets(say[cnt], 120, stdin);
        int len = strlen(say[cnt]);
        say[cnt][len - 1] = '\0';
        ss[cnt].value = get_hash(say[cnt]);
        ss[cnt].id = cnt;
    }
    getchar();
    cnt--;
    sort(mm + 1, mm + 1 + cnt);
    sort(ss + 1, ss + 1 + cnt);
    scanf("%d", &n);
    getchar();
	while (n--) {
        fgets(s, 120, stdin);
        int len = strlen(s);
        s[len - 1] = '\0';
        if (s[0] == '[') {
            ull v = get_hash(s);
            hs *pt = lower_bound(mm + 1, mm + 1 + cnt, hs(v, 0));
            if (pt->value == v)
                printf("%s\n", say[pt->id]);
            else
                printf("what?\n");
        }
        else {
            ull v = get_hash(s);
            hs *pt = lower_bound(ss + 1, ss + 1 + cnt, hs(v, 0));
            if (pt->value == v) {
                int len = strlen(magic[pt->id]);
                for (int i = 1; i < len - 1; i++) s[i - 1] = magic[pt->id][i];
                s[len - 2] = '\0';
                printf("%s\n", s);
            }
            else
                printf("what?\n");
        }
    }
    return 0;
}
