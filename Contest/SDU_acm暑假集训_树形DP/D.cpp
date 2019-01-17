#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

const int MAXN=50005,INF=0x3f3f3f3f;

struct edge{
    int to;
    int next;
};

int n,cnt,minimum;
int head[MAXN];
bool visited[MAXN];
edge e[MAXN*2];
set<int> ans;

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}

int dfs(int u)
{
    visited[u]=true;
    int sum=1,maxone=1;
    bool flag=true;
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(visited[v])continue;
        int num=dfs(v);
        maxone=max(maxone,num);
        sum+=num;
    }
    maxone=max(maxone,n-sum);
    if(maxone<minimum){
        ans.clear();
        ans.insert(u);
        minimum=maxone;
    }
    if(maxone==minimum)
        ans.insert(u);
    return sum;
}

int main()
{
    scanf("%d",&n);
    cnt=0,minimum=INF;
    memset(head,0,sizeof(head));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n-1;i++){
        int from,to;
        scanf("%d %d",&from,&to);
        addedge(from,to);
        addedge(to,from);
    }
    ans.clear();
    dfs(1);
    for(set<int>::iterator it=ans.begin();it!=ans.end();++it)
        printf("%d ",*it);
    return 0;
}
