#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

map<string,double> currency;
int t,c,n;

int main()
{
    scanf("%d",&t);
    while(t--){
        double ans=0;
        scanf("%d %d",&c,&n);
        currency["JD"]=1;
        for(int i=1;i<=c;i++){
            char str[15];
            double rate;
            scanf("%s %lf",str,&rate);
            currency[str]=rate;
        }
        for(int i=1;i<=n;i++){
            double left;
            char str[15];
            scanf("%lf %s",&left,str);
            ans+=left*currency[str];
        }
        printf("%.6f\n",ans);
    }
    return 0;
}

