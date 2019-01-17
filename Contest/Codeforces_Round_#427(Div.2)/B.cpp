#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+10;

int k,sum;
char s[MAXN];
int growth[10];

int main()
{
    scanf("%d",&k);
    scanf("%s",s);
    int len=strlen(s);
    sum=0;
    memset(growth,0,sizeof(growth));
    for(int i=0;i<len;i++){
        int num=s[i]-'0';
        sum+=num;
        growth[9-num]++;
    }
    int diff=k-sum;
    if(diff<=0)
        printf("0\n");
    else{
        int cnt=0,index=9;
        while(diff>0&&index>0){
            if(growth[index]>0){
                diff-=index;
                growth[index]--;
                cnt++;
            }
            else
                index--;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
close
