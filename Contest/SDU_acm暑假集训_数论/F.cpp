#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int t,b;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&b);
        int st=b/2;
        if(st*2==b)st--;
        for(int i=st;i>=0;i--){
            if((long long)i*i%(b-2*i)==0){
                long long ans=(long long)i*i/(b-2*i);
                printf("%lld\n",ans);
                break;
            }
        }
    }
    return 0;
}
