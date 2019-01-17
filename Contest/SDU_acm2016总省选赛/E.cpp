#include<cstdio>
#include<cstring>
using namespace std;

int x[15];
int cnt,ans;

int main()
{
    freopen("explicit.in","r",stdin);
    freopen("explicit.out","w",stdout);
    for(int i=1;i<=10;i++){
        scanf("%d",&x[i]);
        if(x[i]==1)cnt++;
    }
    ans=cnt*(cnt-1)*(31-2*cnt)/6+(10-cnt)*(11-cnt)/2*cnt;
    if(ans%2==0)
        printf("0");
    else
        printf("1");
    return 0;
}
