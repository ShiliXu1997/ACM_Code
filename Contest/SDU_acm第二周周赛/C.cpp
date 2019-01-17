#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=2000,INF=1e9;
int d[MAXN],origin[MAXN],terminal[MAXN];
int road[MAXN][MAXN];
bool visited[MAXN];
queue<int> q;

int min(const int a,const int b)
{
    return (a<b?a:b);
}

int main()
{
    int T,S,D;
    while(scanf("%d %d %d",&T,&S,&D)==3){
        for(int i=1;i<MAXN;i++)
            d[i]=INF;
        for(int i=1;i<MAXN;i++)
            for(int j=1;j<MAXN;j++)
                road[i][j]=INF;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=T;i++){
            int a,b,time;
            scanf("%d %d %d",&a,&b,&time);
            road[a][b]=min(road[a][b],time);
            road[b][a]=road[a][b];
        }
        for(int i=1;i<=S;i++){
            scanf("%d",&origin[i]);
            d[origin[i]]=0;
            q.push(origin[i]);
            visited[origin[i]]=true;
        }
        for(int i=1;i<=D;i++)
            scanf("%d",&terminal[i]);
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=1;i<MAXN;i++)
                if(road[x][i]<INF&&d[i]!=0){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                    }
                    d[i]=min(d[i],d[x]+road[x][i]);
                }
        }
        int ans=INF;
        for(int i=1;i<=D;i++)
            ans=min(ans,d[terminal[i]]);
        printf("%d\n",ans);
    }
	return 0;
}
