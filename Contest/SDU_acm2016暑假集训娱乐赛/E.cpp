#include<cstdio>
using namespace std;

int main()
{
    int format;
    char time[10];
    scanf("%d",&format);
    scanf("%s",time);
    if(format==12){
        if(time[0]!='1'&&time[1]=='0')
            time[0]='1';
        else
        if((time[0]-'0')*10+time[1]-'0'>12)
            time[0]='0';
    }
    else
    if((time[0]-'0')*10+time[1]-'0'>=24)
        time[0]='0';
    if(time[3]-'0'>=6)
        time[3]='0';
    printf("%s",time);
    return 0;
}
