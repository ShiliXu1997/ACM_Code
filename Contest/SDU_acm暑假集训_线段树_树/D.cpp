#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=50005,INF=0x3f3f3f3f;

struct segment{
    int left,right,mid;
    int lx,rx,tx;
    int mark;
};

int n,m;
segment tree[4*MAXN];

void build(int left,int right,int root)
{
    tree[root].left=left;
    tree[root].right=right;
    tree[root].mid=(left+right)>>1;
    tree[root].lx=tree[root].rx=tree[root].tx=right-left+1;
    tree[root].mark=-1;
    if(left==right)return;
    build(left,tree[root].mid,root<<1);
    build(tree[root].mid+1,right,root<<1|1);
}

void push_down(int root)
{
    if(tree[root].mark!=-1){
        if(tree[root].mark==1){
            tree[root<<1].lx=tree[root<<1].rx=tree[root<<1].tx=0;
            tree[root<<1|1].lx=tree[root<<1|1].rx=tree[root<<1|1].tx=0;
        }
        else{
            tree[root<<1].lx=tree[root<<1].rx=tree[root<<1].tx=tree[root<<1].right-tree[root<<1].left+1;
            tree[root<<1|1].lx=tree[root<<1|1].rx=tree[root<<1|1].tx=tree[root<<1|1].right-tree[root<<1|1].left+1;
        }
        tree[root<<1].mark=tree[root].mark;
        tree[root<<1|1].mark=tree[root].mark;
        tree[root].mark=-1;
    }
}

void modify(int left,int right,int val,int root)
{
    if(left<=tree[root].left&&tree[root].right<=right){
        if(val==1)
            tree[root].lx=tree[root].rx=tree[root].tx=0;
        else
            tree[root].lx=tree[root].rx=tree[root].tx=tree[root].right-tree[root].left+1;
        tree[root].mark=val;
        return;
    }
    push_down(root);
    if(left<=tree[root].mid)
        modify(left,right,val,root<<1);
    if(right>tree[root].mid)
        modify(left,right,val,root<<1|1);
    tree[root].lx=tree[root<<1].lx;
    if(tree[root<<1].lx==tree[root<<1].right-tree[root<<1].left+1)
        tree[root].lx+=tree[root<<1|1].lx;
    tree[root].rx=tree[root<<1|1].rx;
    if(tree[root<<1|1].rx==tree[root<<1|1].right-tree[root<<1|1].left+1)
        tree[root].rx+=tree[root<<1].rx;
    tree[root].tx=max(max(tree[root<<1].tx,tree[root<<1|1].tx),max(tree[root].lx,tree[root].rx));
    tree[root].tx=max(tree[root].tx,tree[root<<1].rx+tree[root<<1|1].lx);
}

int query(int num,int root)
{
    push_down(root);
    if(tree[root].tx<num)
        return 0;
    if(tree[root].left==tree[root].right)
        return tree[root].left;
    if(tree[root<<1].tx>=num)
        return query(num,root<<1);
    if(tree[root<<1].rx+tree[root<<1|1].lx>=num)
        return tree[root<<1].right-tree[root<<1].rx+1;
    if(tree[root<<1|1].tx>=num)
        return query(num,root<<1|1);
}

int main()
{
    scanf("%d %d",&n,&m);
    build(1,n,1);
    while(m--){
        int mes;
        scanf("%d",&mes);
        if(mes==1){
            int num,ans;
            scanf("%d",&num);
            ans=query(num,1);
            printf("%d\n",ans);
            if(ans!=0)modify(ans,ans+num-1,1,1);
        }
        else{
            int a,b;
            scanf("%d %d",&a,&b);
            modify(a,a+b-1,0,1);
        }
    }
    return 0;
}
