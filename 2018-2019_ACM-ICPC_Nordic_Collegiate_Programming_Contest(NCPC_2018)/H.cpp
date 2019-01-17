//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 27 Oct 2018 02:35:49 PM CST
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

const int MAXN = 105;

struct mower {
    string name;
    int p, c, t, r, id;
    bool done;

    bool operator<(const mower &another) const
    {
        return p < another.p;
    }
};

int l, n;
char mes[4000];
mower machine[MAXN];

int get_num(string s)
{
    int ans = 0;
    for (auto c: s) ans = ans * 10 + c - '0';
    return ans;
}

bool cmp(mower a, mower b)
{
    return a.id < b.id;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &l, &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        fgets(mes, 4000, stdin);
        int len = strlen(mes), last = 0, step = 0;
        mes[len - 1] = ',';
        string str = string(mes);
        for (int j = 0; j < len; j++) {
            if (mes[j] == ',') {
                if (!step)
                    machine[i].name = str.substr(last, j);
                else {
                    if (step == 1) machine[i].p = get_num(str.substr(last, j - last));
                    if (step == 2) machine[i].c = get_num(str.substr(last, j - last));
                    if (step == 3) machine[i].t = get_num(str.substr(last, j - last));
                    if (step == 4) machine[i].r = get_num(str.substr(last, j - last));
                }
                step++;
                last = j + 1;
            }
        }
        machine[i].id = i;
        machine[i].done = false;
    }
	sort(machine + 1, machine + 1 + n);
    bool flag = false;
    int price;
    for (int i = 1; i <= n; i++) {
        ll sum = (ll)10080 * machine[i].c * machine[i].t;
        if (sum < l * (ll)(machine[i].r + machine[i].t)) continue;
        if (!flag)
            flag = true, price = machine[i].p, machine[i].done = true;
        else {
            if (price == machine[i].p && sum) machine[i].done = true;
        }   
    }
    sort(machine + 1, machine + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        if (machine[i].done) cout << machine[i].name << endl;
    if (!flag) cout << "no such mower" << endl;
    return 0;
}
