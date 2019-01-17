#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
using namespace std;

const int MAXN=35,INF=0x3f3f3f3f;

int n,m;
double exchange[MAXN][MAXN];
double dist[MAXN];
bool boolin[MAXN];
map<string,int> currency;
queue<int> q;

void init()
{
    memset(boolin,false,sizeof(boolin));
    memset(dist,0,sizeof(dist));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            exchange[i][j]=0;
}

double max(const double a,const double b)
{
    return (a>b?a:b);
}

bool spfa(int num)
{
    dist[num]=1;
    q.push(num);
    boolin[num]=true;
    while(!q.empty()){
        int u=q.front();q.pop();boolin[u]=false;
        for(int i=1;i<=n;i++){
            if(dist[i]<dist[u]*exchange[u][i]){
                dist[i]=dist[u]*exchange[u][i];
                if(dist[1]>1)return true;
                if(!boolin[i]){
                    q.push(i);
                    boolin[i]=true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int kase=0;
    while(scanf("%d",&n)==1&&n!=0){
        init();
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            currency[str]=i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            string st,ed;
            int a,b;
            double rate;
            cin>>st;a=currency[st];
            scanf("%lf",&rate);
            cin>>ed;b=currency[ed];
            exchange[a][b]=max(exchange[a][b],rate);
        }
        bool ans=spfa(1);
        printf("Case %d: ",++kase);
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
