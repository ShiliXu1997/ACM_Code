#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=6e5+5,INF=0x3f3f3f3f;

struct segment{
    int left,right,mid;
    int val;
};

int n,m;
int a[MAXN];
segment tree[2*MAXN];

void build(int left,int right,int root)
{
    tree[root].left=left;
    tree[root].right=right;
    tree[root].mid=(left+right)/2;
    if(left==right)
        tree[root].val=a[left];
    else{
        build(left,tree[root].mid,2*root);
        build(tree[root].mid+1,right,2*root+1);
        tree[root].val=max(tree[2*root].val,tree[2*root+1].val);
    }
}

void modify(int index,int num,int root)
{
    if(tree[root].left==tree[root].right&&index==tree[root].left)
        tree[root].val=num;
    else{
        if(index<=tree[root].mid)
            modify(index,num,2*root);
        else
            modify(index,num,2*root+1);
        tree[root].val=max(tree[2*root].val,tree[2*root+1].val);
    }
}

int query(int left,int right,int root)
{
    if(right<tree[root].left||tree[root].right<left)
        return -INF;
    if(left<=tree[root].left&&tree[root].right<=right)
        return tree[root].val;
    int ans=max(query(left,right,2*root),query(left,right,2*root+1));
    return ans;
}

int main()
{
    while(scanf("%d %d",&n,&m)==2){
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,n,1);
        for(int i=1;i<=m;i++){
            char s[5];
            int a,b;
            scanf("%s %d %d",s,&a,&b);
            if(s[0]=='U')
                modify(a,b,1);
            else
                printf("%d\n",query(a,b,1));
        }
    }
    return 0;
}
