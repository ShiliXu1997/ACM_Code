#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;
const long long INF=0x3f3f3f3f3f3f3f3f;

struct edge{
    int to,next;
};

struct segment{
    int left,right,mid;
    long long val,mark;
};

int t,m,n,cnt,step;
int head[MAXN],in[MAXN],out[MAXN];
long long v[MAXN],sum[MAXN];
edge e[MAXN<<1];
segment tree[MAXN<<2];

void build(int left,int right, int root)
{
    tree[root].left=left;
    tree[root].right=right;
    tree[root].mid=(left+right)>>1;
    tree[root].mark=0;
    if(left==right){
        tree[root].val=sum[left];
        return;
    }
    build(left,tree[root].mid,root<<1);
    build(tree[root].mid+1,right,root<<1|1);
    tree[root].val=max(tree[root<<1].val,tree[root<<1|1].val);
}

void push_down(int root)
{
    if(tree[root].mark!=0){
        tree[root<<1].val+=tree[root].mark;
        tree[root<<1|1].val+=tree[root].mark;
        tree[root<<1].mark+=tree[root].mark;
        tree[root<<1|1].mark+=tree[root].mark;
        tree[root].mark=0;
    }
}

void modify(int left,int right,long long num,int root)
{
    if(left<=tree[root].left&&tree[root].right<=right){
        tree[root].val+=num;
        tree[root].mark+=num;
        return;
    }
    push_down(root);
    if(left<=tree[root].mid)
        modify(left,right,num,root<<1);
    if(right>tree[root].mid)
        modify(left,right,num,root<<1|1);
    tree[root].val=max(tree[root<<1].val,tree[root<<1|1].val);
}

long long query(int left,int right,int root)
{
    if(left<=tree[root].left&&tree[root].right<=right)
        return tree[root].val;
    push_down(root);
    long long ans=-INF;
    if(left<=tree[root].mid)
        ans=max(ans,query(left,right,root<<1));
    if(right>tree[root].mid)
        ans=max(ans,query(left,right,root<<1|1));
    return ans;
}

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}

void dfs(int fa,int x)
{
    in[x]=++step;
    if(fa==-1)
        sum[in[x]]=v[x];
    else
        sum[in[x]]=sum[in[fa]]+v[x];
    for(int i=head[x];i>0;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs(x,u);
    }
    out[x]=step;
}

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d %d",&n,&m);
        cnt=0;
        memset(head,0,sizeof(head));
        for(int i=1;i<=n-1;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        for(int i=0;i<=n-1;i++)
            scanf("%lld",&v[i]);
        step=0;
        memset(sum,0,sizeof(sum));
        dfs(-1,0);
        build(1,n,1);
        printf("Case #%d:\n",kase);
        for(int i=1;i<=m;i++){
            int mes;
            scanf("%d",&mes);
            if(mes==0){
                int x;
                long long num,diff;
                scanf("%d %lld",&x,&num);
                diff=num-v[x];
                v[x]=num;
                modify(in[x],out[x],diff,1);
            }
            else{
                int x;
                scanf("%d",&x);
                printf("%lld\n",query(in[x],out[x],1));
            }
        }
    }
    return 0;
}
