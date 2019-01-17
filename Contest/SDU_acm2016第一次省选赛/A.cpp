#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int h,m,s,hh,mm,ss;
        scanf("%d %d %d",&h,&m,&s);
        scanf("%d %d %d",&hh,&mm,&ss);
        m+=s/60;s%=60;
        mm+=ss/60;ss%=60;
        h+=m/60;m%=60;
        hh+=mm/60;mm%=60;
        if(h==hh&&m==mm&&s==ss)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
    return 0;
}
