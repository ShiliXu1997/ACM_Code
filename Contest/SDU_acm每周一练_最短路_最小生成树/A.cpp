#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=205,INF=0x3f3f3f3f;

int n;
int leap[MAXN],dist[MAXN];
bool boolset[MAXN];

bool ok(int num)
{
    return (1<=num&&num<=n);
}

int min(const int a,const int b)
{
    return (a<b?a:b);
}

int main()
{
    int origin,terminal;
    while(scanf("%d %d %d",&n,&origin,&terminal)==3&&n!=0){
        for(int i=1;i<=n;i++)scanf("%d",&leap[i]);
        memset(boolset,false,sizeof(boolset));
        memset(dist,0x3f,sizeof(dist));
        dist[origin]=0;boolset[origin]=true;
        if(ok(origin+leap[origin]))dist[origin+leap[origin]]=1;
        if(ok(origin-leap[origin]))dist[origin-leap[origin]]=1;
        for(int i=2;i<=n;i++){
            int mindist=INF,u;
            for(int j=1;j<=n;j++)
                if(!boolset[j]&&dist[j]!=INF)
                    if(dist[j]<mindist){
                        mindist=dist[j];
                        u=j;
                    }
            boolset[u]=true;
            if(!boolset[u+leap[u]]&&ok(u+leap[u]))
                dist[u+leap[u]]=min(dist[u+leap[u]],dist[u]+1);
            if(!boolset[u-leap[u]]&&ok(u-leap[u]))
                dist[u-leap[u]]=min(dist[u-leap[u]],dist[u]+1);
        }
        int ans;
        if(dist[terminal]==INF)
            ans=-1;
        else
            ans=dist[terminal];
        printf("%d\n",ans);
    }
    return 0;
}
