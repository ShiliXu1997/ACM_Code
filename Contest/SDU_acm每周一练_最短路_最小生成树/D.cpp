#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=500,MAXM=6000,INF=0x3f3f3f3f;

int n,m,w;
int dist[MAXN+5],cnt[MAXN+5];
int path[MAXN+5][MAXN+5];
queue<int> q;
bool boolin[MAXN+5];

int min(const int a,const int b)
{
    return (a<b?a:b);
}

void init()
{
    memset(dist,0x3f,sizeof(dist));
    memset(cnt,0,sizeof(cnt));
    memset(boolin,false,sizeof(boolin));
    dist[1]=0;
}

bool spfa()
{
    init();
    q.push(1);boolin[1]=true;
    while(!q.empty()){
        int u=q.front();q.pop();boolin[u]=false;
        for(int i=1;i<=n;i++)
            if(dist[i]>dist[u]+path[u][i]){
                dist[i]=dist[u]+path[u][i];
                if(!boolin[i]){
                    q.push(i);
                    boolin[i]=true;
                    cnt[i]++;
                    if(cnt[i]>n)return true;
                }
            }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(path,0x3f,sizeof(path));
        scanf("%d %d %d",&n,&m,&w);
        int st,ed,ct;
        while(m--){
            scanf("%d %d %d",&st,&ed,&ct);
            path[st][ed]=min(path[st][ed],ct);
            path[ed][st]=path[st][ed];
        }
        while(w--){
            scanf("%d %d %d",&st,&ed,&ct);
            path[st][ed]=min(path[st][ed],-ct);
        }
        bool ans=spfa();
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
