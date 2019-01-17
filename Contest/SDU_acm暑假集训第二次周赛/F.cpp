#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,MAXL=150;
const int TEN[4]={1,10,100,1000};

struct bignumber{
    int d[MAXL];

    bignumber()
    {
        *this=bignumber(string("0"));
    }

    bignumber(string s)
    {
        int len=s.size();
        d[0]=(len-1)/4+1;
        for(int i=1;i<MAXL;i++)d[i]=0;
        for(int i=len-1;i>=0;i--){
            int j=(len-i-1)/4+1,k=(len-i-1)%4;
            d[j]+=TEN[k]*(s[i]-'0');
        }
        while(d[0]>1&&d[d[0]]==0)d[0]--;
    }

    string tostring()
    {
        string s("");
        int i,temp;
        for(i=3;i>=1;i--)if(d[d[0]]>=TEN[i])break;
        temp=d[d[0]];
        for(int j=i;j>=0;j--){
            s=s+(char)(temp/TEN[j]+'0');
            temp%=TEN[j];
        }
        for(i=d[0]-1;i>0;i--){
            temp=d[i];
            for(int j=3;j>=0;j--){
                s=s+(char)(temp/TEN[j]+'0');
                temp%=TEN[j];
            }
        }
        return s;
    }

    bignumber operator+(const bignumber &another)
    {
        bignumber c;
        c.d[0]=max(d[0],another.d[0]);
        int x=0;
        for(int i=1;i<=c.d[0];i++){
            x=x+d[i]+another.d[i];
            c.d[i]=x%10000;
            x/=10000;
        }
        while(x!=0){
            c.d[++c.d[0]]=x%10000;
            x/=10000;
        }
        return c;
    }
};


int n,k;
bignumber dp[MAXN];

int main()
{
//    freopen("input.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    dp[0]=bignumber(string("1"));
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++)
        for(int j=i;j<=n;j++)
            dp[j]=dp[j]+dp[j-i];
    cout<<dp[n].tostring();
    return 0;
}
