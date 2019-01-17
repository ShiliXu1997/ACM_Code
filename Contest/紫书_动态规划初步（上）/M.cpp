#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;

const int MAXN=130,MAXS=300,INF=0x3f3f3f3f;

int s,m,n;
int c[MAXN],p[MAXN];
int dp[MAXS][MAXS];

int main()
{
    string line;
    stringstream stream;
    while(getline(cin,line)){
        stream<<line;
        stream>>s>>m>>n;
        stream.str("");stream.clear();
        if(s==0)break;
        int curr1=0,curr2=0,sum=0;
        for(int i=1;i<=m;i++){
            getline(cin,line);
            stream<<line;
            int x,course=0;
            stream>>x;
            sum+=x;
            while(stream>>x)course|=(1<<(x-1));
            stream.str("");stream.clear();
            curr2|=(curr1&course);
            curr1|=course;
        }
        memset(c,0,sizeof(c));
        memset(dp,0x3f,sizeof(dp));
        dp[curr1][curr2]=sum;
        for(int i=1;i<=n;i++){
            getline(cin,line);
            stream<<line;
            stream>>p[i];
            int x;
            while(stream>>x)c[i]|=(1<<(x-1));
            stream.str("");stream.clear();
            for(int j=(1<<s)-1;j>=0;j--)
                for(int k=(1<<s)-1;k>=j;k--){
                    if(dp[k][j]>=INF)continue;
                    int s1=k|c[i],s2=(k&c[i])|j;
                    dp[s1][s2]=min(dp[s1][s2],dp[k][j]+p[i]);
                }
        }
        cout<<dp[(1<<s)-1][(1<<s)-1]<<endl;
    }
    return 0;
}
