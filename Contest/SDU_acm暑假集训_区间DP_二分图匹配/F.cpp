#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=505;

int n,k;
int xmatch[MAXN],ymatch[MAXN];
bool visited[MAXN];
vector<int> connect[MAXN];

bool dfs(int u)
{
    for(int i=0;i<connect[u].size();i++){
        int j=connect[u][i];
        if(!visited[j]){
            visited[j]=true;
            if(ymatch[j]==0||dfs(ymatch[j])){
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
    memset(xmatch,0,sizeof(xmatch));
    memset(ymatch,0,sizeof(ymatch));
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        if(dfs(i))ans++;
    }
    return ans;
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        int from,to;
        scanf("%d %d",&from,&to);
        connect[from].push_back(to);
    }
    printf("%d\n",hungary());
    return 0;
}
