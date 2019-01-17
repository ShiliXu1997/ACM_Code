#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=150;

int n,k;
int manage[MAXN];
vector<int> child[MAXN];

void dfs(int x)
{
    manage[x]=0;
    for(int i=0;i<child[x].size();i++){
        int j=child[x][i];
        if(manage[j]==-1)dfs(j);
        manage[x]+=manage[j]+1;
    }
}

int main()
{
    while(scanf("%d %d",&n,&k)==2){
        memset(manage,0xff,sizeof(manage));
        for(int i=1;i<MAXN;i++)child[i].clear();
        for(int i=1;i<n;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            child[from].push_back(to);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(manage[i]==-1)dfs(i);
            if(manage[i]==k)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
