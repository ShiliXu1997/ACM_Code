#define LOCAL
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;

const int MAXN=155,INF=0x3f3f3f3f;

int n,cnt;
string departure,destination;
int bustime[MAXN][MAXN];
int dist[MAXN];
bool boolset[MAXN];
map<string,int> station;

int min(const int a,const int b)
{
    return (a<b?a:b);
}
int main()
{
#ifdef LOCAL
    freopen("input","r",stdin);
#endif
    while(scanf("%d",&n)==1&&n!=-1){
        cin>>departure>>destination;
        station.clear();cnt=0;
        memset(bustime,0x3f,sizeof(bustime));
        station[departure]=++cnt;
        station[destination]=++cnt;
        for(int i=1;i<=n;i++){
            string s,e;
            int time,x,y;
            map<string,int>::iterator it;
            cin>>s>>e;scanf("%d",&time);
            if(!station.count(s))station[s]=++cnt;
            if(!station.count(e))station[e]=++cnt;
            it=station.find(s);x=it->second;
            it=station.find(e);y=it->second;
            bustime[x][y]=min(time,bustime[x][y]);
            bustime[y][x]=bustime[x][y];
        }
        if(departure==destination)
            printf("0\n");
        else{
            memset(boolset,false,sizeof(boolset));
            for(int i=2;i<=cnt;i++)dist[i]=bustime[1][i];
            dist[1]=0;boolset[1]=true;
            for(int i=2;i<=cnt;i++){
                int mindist=INF,u;
                for(int j=1;j<=cnt;j++)
                    if(!boolset[j]&&dist[j]<mindist){
                        u=j;
                        mindist=dist[j];
                    }
                boolset[u]=true;
                for(int j=1;j<=cnt;j++)
                    if(!boolset[j]&&bustime[u][j]<INF)
                        dist[j]=min(dist[j],dist[u]+bustime[u][j]);
            }
            if(dist[2]>=INF)
                printf("-1\n");
            else
                printf("%d\n",dist[2]);
        }
    }
    return 0;
}
