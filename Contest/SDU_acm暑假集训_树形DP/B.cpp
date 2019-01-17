#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=250;

char buff[250200];
int n,m,cnt;
int cost[MAXN];
bool independent[MAXN];
int dp[MAXN][MAXN];
map<string,int> id;
vector<int> child[MAXN];

int dfs(int u)
{
    int tot=1,sz=child[u].size();
    dp[u][0]=0;
    for(int i=0;i<sz;i++){
        int v=child[u][i];
        int t=dfs(v);
        tot+=t;
        for(int j=tot;j>=1;j--){
            int lim=min(t,j);
            for(int k=1;k<=lim;k++)
                dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]);
        }
    }
    for(int i=1;i<=tot;i++)
        dp[u][i]=min(dp[u][i],cost[u]);
    return tot;
}

int main()
{
    stringstream stream;
    string name;
    while(gets(buff)){
        if(buff[0]=='#')break;
        sscanf(buff,"%d %d",&n,&m);
        for(int i=0;i<=n;i++){
            child[i].clear();
            independent[i]=true;
        }
        id.clear();
        cnt=0;
        memset(dp,0x3f,sizeof(dp));
        memset(cost,0x3f,sizeof(cost));
        for(int i=1;i<=n;i++){
            gets(buff);
            stream.clear();
            stream.str(buff);
            stream>>name;
            if(!id.count(name))id[name]=++cnt;
            int u=id[name];
            stream>>cost[u];
            while(stream>>name){
                if(!id.count(name))id[name]=++cnt;
                child[u].push_back(id[name]);
                independent[id[name]]=false;
            }
        }
        for(int i=1;i<=n;i++)
            if(independent[i])child[0].push_back(i);
        dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
