#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

char buff[MAXN];

bool isD(int i)
{
    return (buff[i + 1] == 'a' && buff[i + 2] == 'n' && buff[i + 3] == 'i' && buff[i + 4] == 'l');
}

bool isO(int i)
{
    return (buff[i + 1] == 'l' && buff[i + 2] == 'y' && buff[i + 3] == 'a');
}

bool isS(int i)
{
    return (buff[i + 1] == 'l' && buff[i + 2] == 'a' && buff[i + 3] == 'v' && buff[i + 4] == 'a');
}

bool isA(int i)
{
    return (buff[i + 1] == 'n' && buff[i + 2] == 'n');
}

bool isN(int i)
{
    return (buff[i + 1] == 'i' && buff[i + 2] == 'k' && buff[i + 3] == 'i' && buff[i + 4] == 't' && buff[i + 5] == 'a');
}

int main()
{
    scanf("%s", buff);
    int len = strlen(buff), cnt = 0;
    for (int i = 0; i < len; i++) {
        if (buff[i] == 'D' && (len - i) >=5 && isD(i)) cnt++;
        if (buff[i] == 'O' && (len - i) >=4 && isO(i)) cnt++;
        if (buff[i] == 'S' && (len - i) >=5 && isS(i)) cnt++;
        if (buff[i] == 'A' && (len - i) >=3 && isA(i)) cnt++;
        if (buff[i] == 'N' && (len - i) >=6 && isN(i)) cnt++;
    }
    if (cnt == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
