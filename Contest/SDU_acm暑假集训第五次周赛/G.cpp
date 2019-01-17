#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e5+5;

char t[MAXN];
int n;
int nextval[MAXN];

void solve(char *t)
{
    memset(nextval,0,sizeof(nextval));
    nextval[0]=-1;
    int len=strlen(t),k=-1,j=0;
    while(j<len){
        if(k==-1||t[k]==t[j]){
            k++;j++;
            nextval[j]=k;
        }
        else
            k=nextval[k];
    }
    if(len%(len-nextval[len])==0&&nextval[len]!=0)
        printf("0\n");
    else{
        int ans;
        while(len-nextval[len]<=nextval[len])
            len=nextval[len];
        ans=len-2*nextval[len];
        printf("%d\n",ans);
    }
}

int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%s",t);
        solve(t);
    }
    return 0;
}
