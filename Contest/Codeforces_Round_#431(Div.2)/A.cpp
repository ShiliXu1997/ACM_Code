#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

int n;
int a[MAXN];

bool odd(int x)
{
    return x&1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(odd(n)&&odd(a[1])&&odd(a[n]))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
