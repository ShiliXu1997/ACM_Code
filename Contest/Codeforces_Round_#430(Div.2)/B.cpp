#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double EPS=1e-8;

int n,r,d;

int main()
{
    scanf("%d %d",&r,&d);
    scanf("%d",&n);
    int ans=0;
    while(n--){
        int x,y,t;
        scanf("%d %d %d",&x,&y,&t);
        double dis=sqrt(x*x+y*y);
        if(dis-(r-d)-t>=-EPS&&r-dis-t>=-EPS)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
