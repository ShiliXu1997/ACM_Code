#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1005;

int t,n,m;
int fa[MAXN];

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)fa[i]=i;
        while(m--){
            int a,b,p,q;
            scanf("%d %d",&a,&b);
            p=findfather(a);
            q=findfather(b);
            if(p!=q)fa[q]=p;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(i==fa[i])cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
