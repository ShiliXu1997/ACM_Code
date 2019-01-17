#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN=200005;

int t,n;
int a[MAXN],l[MAXN],r[MAXN];
map<int,int> m;

bool judge(int left,int right)
{
    if(left>=right)return true;
    for(int i=0;i<=(right-left)>>1;i++){
        if(l[left+i]<left&&r[left+i]>right)
            return judge(left,left+i-1)&&judge(left+i+1,right);
        if(l[right-i]<left&&r[right-i]>right)
            return judge(left,right-i-1)&&judge(right-i+1,right);
    }
    return false;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        m.clear();
        for(int i=1;i<=n;i++){
            if(!m.count(a[i]))
                l[i]=0;
            else
                l[i]=m[a[i]];
            m[a[i]]=i;
        }
        m.clear();
        for(int i=n;i>=1;i--){
            if(!m.count(a[i]))
                r[i]=n+1;
            else
                r[i]=m[a[i]];
            m[a[i]]=i;
        }
        if(judge(1,n))
            printf("non-boring\n");
        else
            printf("boring\n");
    }
    return 0;
}
