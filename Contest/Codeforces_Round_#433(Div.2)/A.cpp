#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    scanf("%d",&n);
    for(int i=n-2;i>=1;i--)
        if(gcd(i,n-i)==1&&i<n-i){
            printf("%d %d\n",i,n-i);
            break;
        }
    return 0;
}
