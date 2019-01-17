#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=5e5+5;

struct edge{
    int to,next;
};

struct segment{
    int left,right,mid;
    bool val,mark;
};

int n,q,cnt,num;
int head[MAXN],fa[MAXN],in[MAXN],out[MAXN];
edge e[2*MAXN];
segment tree[4*MAXN];
bool flag;

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}

void dfs(int x)
{
    in[x]=++num;
    for(int i=head[x];i!=0;i=e[i].next){
        int u=e[i].to;
        if(u!=fa[x]){
            fa[u]=x;
            dfs(u);
        }
    }
    out[x]=num;
}

void build(int left,int right,int root)
{
    tree[root].left=left;
    tree[root].right=right;
    tree[root].mid=(left+right)>>1;
    tree[root].val=false;
    tree[root].mark=false;
    if(left==right)return;
    build(left,tree[root].mid,root<<1);
    build(tree[root].mid+1,right,root<<1|1);
}

void push_down(int root)
{
    if(tree[root].mark){
        tree[root<<1].val=true;
        tree[root<<1|1].val=true;
        tree[root<<1].mark=true;
        tree[root<<1|1].mark=true;
        tree[root].mark=false;
    }
}

void modify(int left,int right,bool num,int root)
{
    if(right<tree[root].left||tree[root].right<left)
        return;
    if(left<=tree[root].left&&tree[root].right<=right){
        if(!tree[root].val)flag=false;
        if(num)tree[root].mark=true;
        tree[root].val=num;
        return;
    }
    push_down(root);
    if(left<=tree[root].mid)
        modify(left,right,num,root<<1);
    if(right>tree[root].mid)
        modify(left,right,num,root<<1|1);
    if(tree[root<<1].val&&tree[root<<1|1].val)
        tree[root].val=true;
    else
        tree[root].val=false;
}

void query(int left,int right,int root)
{
    if(left<=tree[root].left&&tree[root].right<=right){
        if(!tree[root].val)flag=false;
        return;
    }
    push_down(root);
    if(left<=tree[root].mid)
        query(left,right,root<<1);
    if(right>tree[root].mid)
        query(left,right,root<<1|1);
    if(tree[root<<1].val&&tree[root<<1|1].val)
        tree[root].val=true;
    else
        tree[root].val=false;
}

int main()
{
    scanf("%d",&n);
    cnt=0;num=0;
    memset(head,0,sizeof(head));
    memset(fa,0,sizeof(fa));
    for(int i=1;i<=n-1;i++){
        int from,to;
        scanf("%d %d",&from,&to);
        addedge(from,to);
        addedge(to,from);
    }
    dfs(1);
    build(1,num,1);
    scanf("%d",&q);
    while(q--){
        int mes,x;
        scanf("%d %d",&mes,&x);
        if(mes==1){
            flag=true;
            modify(in[x],out[x],true,1);
            if(!flag)
                modify(in[fa[x]],in[fa[x]],false,1);
        }
        if(mes==2)
            modify(in[x],in[x],false,1);
        if(mes==3){
            flag=true;
            query(in[x],out[x],1);
            if(flag)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}
