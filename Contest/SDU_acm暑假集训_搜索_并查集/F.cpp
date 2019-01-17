#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN=2e5+5;

int n,x;
int dist_a[MAXN],dist_b[MAXN];
vector<int> vertices[MAXN];
queue<int> q;

void bfs(int dist[],int x)
{
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<vertices[u].size();i++)
            if(dist[vertices[u][i]]==0&&vertices[u][i]!=x){
                dist[vertices[u][i]]=dist[u]+1;
                q.push(vertices[u][i]);
            }
    }
}

int main()
{
    memset(dist_a,0,sizeof(dist_a));
    memset(dist_b,0,sizeof(dist_b));
    scanf("%d %d",&n,&x);
    int from,to;
    for(int i=1;i<=n-1;i++){
        scanf("%d %d",&from,&to);
        vertices[from].push_back(to);
        vertices[to].push_back(from);
    }
    bfs(dist_a,1);
    bfs(dist_b,x);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(dist_a[i]>dist_b[i])
            ans=max(ans,dist_a[i]*2);
    printf("%d\n",ans);
    return 0;
}
