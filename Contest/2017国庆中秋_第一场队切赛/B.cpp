#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 1005;

int n;
char trainee[MAXN][10];
set<string> s;

int main()
{
    while (scanf("%d", &n) == 1) {
        s.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%s", trainee[i]);
            int len = strlen(trainee[i]);
            sort(trainee[i], trainee[i] + len);
            int newlen = unique(trainee[i], trainee[i] + len) - trainee[i];
            trainee[i][newlen ] = '\0';
            string str(trainee[i]);
            s.insert(str);
        }
        printf("%d\n", s.size());
    }
    return 0;
}
