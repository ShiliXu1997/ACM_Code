#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=200010;

int n;
int a[MAXN],b[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int k;
    for(int i=0;i<n;i++)
        if(a[i]>0){
            k=i;
            break;
        }
    int pos;
    for(int i=0;i<n;i++)
        if(b[i]==a[k]){
            pos=i;
            break;
        }
    int cnt=0;
    bool flag=true;
    while(flag&&cnt<=n){
        k=(k+1)%n;
        if(a[k]==0)k=(k+1)%n;
        pos=(pos+1)%n;
        if(b[pos]==0)pos=(pos+1)%n;
        if(a[k]!=b[pos])flag=false;
        cnt++;
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
