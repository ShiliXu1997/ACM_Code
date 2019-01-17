#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;

char s[MAXN],t[MAXN];
int nextval[MAXN];

void getnext(char *t)
{
    memset(nextval,0,sizeof(nextval));
    nextval[0]=-1;
    int len=strlen(t),k=-1,j=0;
    while(j<len-1){
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

bool kmp(char *s,char *t)
{
    int slen=strlen(s),tlen=strlen(t);
    int i=0,j=0;
    while(i<slen&&j<tlen){
        if(j==-1||s[i]==t[j]){
            i++;j++;
        }
        else
            j=nextval[j];
    }
    if(j==tlen)
        return true;
    else
        return false;
}

int main()
{
    while(scanf("%s %s",s,t)==2){
        getnext(t);
        int len=strlen(s);
        for(int i=0;i<len;i++)
            s[len+i]=s[i];
        s[2*len]='\0';
        if(kmp(s,t))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
