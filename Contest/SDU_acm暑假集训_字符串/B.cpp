#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1000005;

char s[MAXN];
int nextval[MAXN];

void getnext(char *t)
{
    memset(nextval,0,sizeof(nextval));
    nextval[0]=-1;
    int len=strlen(t),k=-1,j=0;
    while(j<len){
        if(k==-1||t[k]==t[j]){
            k++;j++;
            int w=k;
            while(t[w]==t[j]&&w!=-1)w=nextval[w];
            nextval[j]=w;
        }
        else
            k=nextval[k];
    }
}

int main()
{
    while(scanf("%s",s)==1&&s[0]!='.'){
        getnext(s);
        int n=strlen(s);
        if(n%(n-nextval[n])==0)
            printf("%d\n",n/(n-nextval[n]));
        else
            printf("1\n");
    }
    return 0;
}
