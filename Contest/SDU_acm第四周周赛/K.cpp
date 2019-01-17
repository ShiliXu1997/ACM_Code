#include<cstdio>
#include<cstring>
using namespace std;

const double INF=0x3f3f3f3f;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b,ansa,ansb;
        double ansrate=INF;
        scanf("%d",&n);
        while(n--){
            scanf("%d %d",&a,&b);
            double rate=(double)a/b;
            if(rate<ansrate){
                ansrate=rate;
                ansa=a;
                ansb=b;
            }
        }
        printf("%d %d\n",ansa,ansb);
    }
    return 0;
}
