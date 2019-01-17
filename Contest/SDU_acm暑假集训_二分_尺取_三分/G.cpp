#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5,INF=0x3f3f3f3f;

int n,k,tmp,ans,sum,i,j;
char s[MAXN];

int main()
{
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    ans=0;
    tmp=k;
    i=0;sum=0;
    for(j=0;j<n;j++){
        if(s[j]=='a'){
            sum++;
            ans=max(ans,sum);
        }
        else{
            if(tmp>0){
                tmp--;
                sum++;
            }
            else{
                if(i==j)i++;
                while(tmp==0&&i<j){
                    if(s[i]=='b')tmp++;
                    i++;
                    sum--;
                    if(i==j)i++;
                }
                if(tmp>0){
                    tmp--;
                    sum++;
                }
            }
            ans=max(ans,sum);
        }
    }
    tmp=k;
    i=0;sum=0;
    for(j=0;j<n;j++){
        if(s[j]=='b'){
            sum++;
            ans=max(ans,sum);
        }
        else{
            if(tmp>0){
                tmp--;
                sum++;
            }
            else{
                if(i==j)i++;
                while(tmp==0&&i<j){
                    if(s[i]=='a')tmp++;
                    i++;
                    sum--;
                    if(i==j)i++;
                }
                if(tmp>0){
                    tmp--;
                    sum++;
                }
            }
            ans=max(ans,sum);
        }
    }
    printf("%d",ans);
    return 0;
}
