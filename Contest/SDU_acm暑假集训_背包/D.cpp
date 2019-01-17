#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

int n;
int dp[MAXN][10005];

struct bottle{
    int remain;
    int volume;

    bool operator<(const bottle &another)const
    {
        return volume>another.volume;
    }
};

bottle a[MAXN];

int main()
{
    scanf("%d",&n);
    int sum=0,tot=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].remain);
        sum+=a[i].remain;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].volume);
        tot+=a[i].volume;
    }
    sort(a+1,a+1+n);
    int index=1,s=sum,time=0,max_remain=0;
    while(s>0)s-=a[index++].volume;
    index--;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=tot;j>=a[i].volume;j--)
            for(int k=1;k<=index;k++)
                dp[k][j]=max(dp[k][j],dp[k-1][j-a[i].volume]+a[i].remain);
    for(int i=sum;i<=tot;i++)
        max_remain=max(max_remain,dp[index][i]);
    time=sum-max_remain;
    printf("%d %d\n",index,time);
    return 0;
}
