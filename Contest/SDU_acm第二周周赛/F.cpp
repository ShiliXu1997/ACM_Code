#include<cstdio>
using namespace std;

int main()
{
    int n,x,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==0)cnt++;
    }
    if(cnt==0&&n==1||cnt==1&&n>1)
        printf("YES\n");
    else
        printf("NO\n");
	return 0;
}
