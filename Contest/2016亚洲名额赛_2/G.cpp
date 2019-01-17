#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

char s[MAXN];
bool visited[100*MAXN];

int main()
{
    memset(visited, false, sizeof(visited));
    scanf("%s",s);
    int len = strlen(s);
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j <= len - i;j++) {
            int num = 0;
            for (int k = j; k < j + i; k++)
                num = num * 10 + (s[k] - '0');
            visited[num] = true;
        }
    }
    for (int i = 1; i <= 9999999; i++)
        if(!visited[i]){
            printf("%d\n", i);
            break;
        }
    return 0;
}
