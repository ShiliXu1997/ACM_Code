#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,SIZE=2;

struct trie{
    int cnt;
    trie *child[SIZE];
    trie()
    {
        memset(child,NULL,sizeof(child));
        cnt=0;
    }
};

int t,n;
int a[MAXN];
trie *root;

void insert(int x)
{
    trie *p=root;
    p->cnt++;
    for(int i=30;i>=0;i--){
        int id=x>>i&1;
        if(p->child[id]==NULL)
            p->child[id]=new trie();
        p->child[id]->cnt++;
        p=p->child[id];
    }
}

void remove(int x)
{
    trie *p=root;
    p->cnt--;
    for(int i=30;i>=0;i--){
        int id=x>>i&1;
        p->child[id]->cnt--;
        p=p->child[id];
    }
}

int query(int x)
{
    int ans=0;
    trie *p=root;
    for(int i=30;i>=0;i--){
        int id=x>>i&1;
        if(p->child[id^1]!=NULL&&p->child[id^1]->cnt>0){
            id^=1;
            ans+=(1<<i);
        }
        p=p->child[id];
    }
    return ans;
}

void del(trie *root)
{
    for(int i=0;i<SIZE;i++)
        if(root->child[i]!=NULL)
            del(root->child[i]);
    delete(root);
}

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        root=new trie();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            insert(a[i]);
        }
        int ans=0;
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++){
                int num=a[i]+a[j];
                remove(a[i]);
                remove(a[j]);
                ans=max(ans,query(num));
                insert(a[i]);
                insert(a[j]);
            }
        printf("%d\n",ans);
        del(root);
    }
    return 0;
}
