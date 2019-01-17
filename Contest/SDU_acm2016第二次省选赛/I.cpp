#include<cstdio>
using namespace std;

int mmr[15];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&mmr[i]);
            if(6000<mmr[i]&&mmr[i]<=9999)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
