#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long l,r,x,y,k;

int main()
{
    scanf("%lld %lld %lld %lld %lld",&l,&r,&x,&y,&k);
    bool flag=false;
    for(long long i=x;i<=y;i++){
        long long ans=i*k;
        if(l<=ans&&ans<=r){
            flag=true;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
