#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=5e5+5,INF=0x3f3f3f3f;

struct segment{
    int left,right,mid;
    long long sum;
    int mark;
};

int n,m;
int a[MAXN];
segment tree[4*MAXN];

void build(int left,int right,int root)
{
    tree[root].left=left;
    tree[root].right=right;
    tree[root].mid=(left+right)>>1;
    tree[root].mark=0;
    if(left==right)
        tree[root].sum=a[left];
    else{
        build(left,tree[root].mid,root<<1);
        build(tree[root].mid+1,right,root<<1|1);
        tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    }
}

void push_down(int root)
{
    if(tree[root].mark!=0){
        tree[root<<1].sum+=(long long)tree[root].mark*(tree[root<<1].right-tree[root<<1].left+1);
        tree[root<<1|1].sum+=(long long)tree[root].mark*(tree[root<<1|1].right-tree[root<<1|1].left+1);
        tree[root<<1].mark+=tree[root].mark;
        tree[root<<1|1].mark+=tree[root].mark;
        tree[root].mark=0;
    }
}

void modify(int left,int right,int num,int root)
{
    if(right<tree[root].left||tree[root].right<left)
        return;
    if(left<=tree[root].left&&tree[root].right<=right){
        tree[root].sum+=(long long)num*(tree[root].right-tree[root].left+1);
        tree[root].mark+=num;
        return;
    }
    push_down(root);
    modify(left,right,num,root<<1);
    modify(left,right,num,root<<1|1);
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
}

long long query(int left,int right,int root)
{
    if(right<tree[root].left||tree[root].right<left)
        return 0;
    if(left<=tree[root].left&&tree[root].right<=right)
        return tree[root].sum;
    push_down(root);
    return query(left,right,root<<1)+query(left,right,root<<1|1);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++){
        char s[5];
        scanf("%s",s);
        if(s[0]=='Q'){
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%lld\n",query(a,b,1));
        }
        else{
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            modify(a,b,c,1);
        }
    }
    return 0;
}
