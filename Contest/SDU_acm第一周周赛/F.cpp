#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e7;
bool boolprime[MAXN+10],visited[MAXN+10];

void swap(char *a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}

void init()
{
    memset(boolprime,false,sizeof(boolprime));
    boolprime[0]=boolprime[1]=true;
    for(int i=2;i*i<=MAXN;i++)
        if(!boolprime[i])
            for(int j=i*i;j<=MAXN;j+=i)
                boolprime[j]=true;
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        char str[10];
        int len,ans=0;
        scanf("%s",str);
        len=strlen(str);
        sort(str,str+len);
        if(str[0]=='0'){
            int index=0;
            while(str[index]=='0'&&index<len-1)index++;
            swap(&str[0],&str[index]);
        }
        memset(visited,false,sizeof(visited));
        do{
            int sum=0;
            for(int i=1;i<=len;i++){
                sum=sum*10+(str[i-1]-'0');
                if(!boolprime[sum]&&!visited[sum]){
                    ans++;
                    visited[sum]=true;
                }
            }
        }while(next_permutation(str,str+len));
        printf("%d\n",ans);
    }
	return 0;
}
