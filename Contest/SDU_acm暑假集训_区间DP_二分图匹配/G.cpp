#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=100;
const int DIR[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int m,n,k;
bool visited[MAXN*MAXN];
bool hole[MAXN][MAXN];
int xmatch[MAXN*MAXN],ymatch[MAXN*MAXN];
vector<int> connect[MAXN];

bool dfs(int u)
{
    for(int i=0;i<connect[u].size();i++){
        int j=connect[u][i];
        if(!visited[j]){
            visited[j]=true;
            if(ymatch[j]==-1||dfs(ymatch[j])){
                xmatch[u]=j;
                ymatch[j]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans=0;
    memset(xmatch,0xff,sizeof(xmatch));
    memset(ymatch,0xff,sizeof(ymatch));
    for(int i=1;i<=n*m;i++){
        memset(visited,false,sizeof(visited));
        if(dfs(i))ans++;
    }
    return ans;
}

int main()
{
    memset(hole,false,sizeof(hole));
    scanf("%d %d %d",&m,&n,&k);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        hole[y][x]=true;
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if((i+j)%2==0&&!hole[i][j])
                for(int k=0;k<4;k++){
                    int y=i+DIR[k][0],x=j+DIR[k][1];
                    if(1<=y&&y<=m&&1<=x&&x<=n&&!hole[y][x]){
                        connect[(i-1)*n+j].push_back((y-1)*n+x);
                    }
                }
    if(hungary()*2==n*m-k)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
