#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN=9999+5;

bool isbissextile[MAXN];
int day[MAXN],days[MAXN];

bool runnian(int num)
{
    return ((num%4==0&&num%100!=0)||num%400==0);
}

int main()
{
    memset(isbissextile,false,sizeof(isbissextile));
    memset(day,0,sizeof(day));
    memset(days,0,sizeof(days));
    for(int i=1920;i<=9999;i++)
        if(runnian(i))isbissextile[i]=true;
    day[1928]=2;days[1928]=6;
    for(int i=1929;i<=9999;i++){
        int d;
        if(runnian(i))
            d=366;
        else
            d=365;
        day[i]=(day[i-1]+d)%7;
        if(day[i]==3||day[i]==4||day[i]==5||day[i]==6)days[i]=5;
        if(day[i]==1)days[i]=9;
        if(day[i]==2||day[i]==0)days[i]=6;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int y;
        scanf("%d",&y);
        printf("%d\n",days[y]);
    }
    return 0;
}
