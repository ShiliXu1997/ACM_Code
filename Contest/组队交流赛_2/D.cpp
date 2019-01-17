#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=100005;

int t,n;
int a[MAXN];

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d",&n);
        int x=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            x^=a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if((x^a[i])<a[i])ans++;
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
