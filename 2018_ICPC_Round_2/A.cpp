//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 12时40分30秒
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

struct tri {
	int a, b, c;

	tri() {}
	tri(int u, int v, int w) : a(u), b(v), c(w) {}

	bool operator<(const tri &another) const
	{
		if (a != another.a) return a < another.a;
		if (b != another.b) return b < another.b;
		return c < another.c;
	}
};

int l[10];
set<tri> s;

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 5; i++) cin >> l[i];
    sort(l + 1, l + 6);
    for(int i = 1; i <= 3; i++){
        for(int j = i + 1; j <= 4; j++){
            for (int k = j + 1; k <= 5; k++)
                if (l[i] + l[j] > l[k] && l[k] - l[i] < l[j]) s.insert(tri(l[i], l[j], l[k]));
        }
    }
    cout << s.size() << endl;
}



