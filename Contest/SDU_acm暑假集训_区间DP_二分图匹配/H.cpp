#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=10005;

int n,m;
bool visited[MAXN];
int xmatch[MAXN],ymatch[MAXN];
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
    for(int i=0;i<n;i++)
        if(xmatch[i]==-1){
            memset(visited,false,sizeof(visited));
            if(dfs(i))ans++;
        }
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    while(m--){
        int from,to;
        scanf("%d %d",&from,&to);
        connect[from].push_back(to);
    }
    if(hungary()==n)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
