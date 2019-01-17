#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN=100005;

struct point{
    int kind,pos,up,down;

    bool operator<(const point &another)const
    {
        if(pos==another.pos)
            return kind<another.kind;
        return pos<another.pos;
    }
};

int t,n,cnt,tot;
int height[MAXN*2];
long long a[MAXN*2];
point p[MAXN*2];
map<int,int> id;

void swap(int *a,int *b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

int lowbit(int x)
{
    return (x&-x);
}

void modify(int x,int num)
{
    while(x<=tot){
        a[x]+=num;
        x+=lowbit(x);
    }
}

long long sum(int x)
{
    long long ans=0;
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cnt=0;tot=0;
        id.clear();
        for(int i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(!id.count(y1)){
                id[y1]=0;
                height[++tot]=y1;
            }
            if(!id.count(y2)){
                id[y2]=0;
                height[++tot]=y2;
            }
            if(x1==x2){
                if(y1>y2)swap(&y1,&y2);
                p[++cnt].kind=1;p[cnt].pos=x1;
                p[cnt].down=y1;p[cnt].up=y2;
            }
            else
            if(y1==y2){
                if(x1>x2)swap(&x1,&x2);
                p[++cnt].kind=0;p[cnt].pos=x1;
                p[cnt].up=p[cnt].down=y1;
                p[++cnt].kind=2;p[cnt].pos=x2;
                p[cnt].up=p[cnt].down=y2;
            }
        }
        sort(height+1,height+1+tot);
        for(int i=1;i<=tot;i++)
            id[height[i]]=i;
        sort(p+1,p+1+cnt);
        memset(a,0,sizeof(a));
        long long ans=0;
        for(int i=1;i<=cnt;i++){
            if(p[i].kind==0)
                modify(id[p[i].up],1);
            if(p[i].kind==1)
                ans+=(sum(id[p[i].up])-sum(id[p[i].down]-1));
            if(p[i].kind==2)
                modify(id[p[i].up],-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
