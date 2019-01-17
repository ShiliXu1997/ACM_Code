#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,INF=0x3f3f3f3f;

int n;
char s[MAXN];
int dp[MAXN];

bool ispalindrome(int l,int r)
{
    int i=l,j=r;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<=len-1;i++){
            if(ispalindrome(0,i))
                dp[i]=1;
            else{
                dp[i]=i+1;
                for(int j=0;j<=i-1;j++)
                    if(ispalindrome(j+1,i))
                        dp[i]=min(dp[i],dp[j]+1);
            }
        }
        printf("%d\n",dp[len-1]);
    }
    return 0;
}
