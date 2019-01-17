#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

struct text{
    char plain[MAXN],cipher[MAXN];
    int len;

    bool operator<(const text &another)const
    {
        return len>another.len;
    }

};

int n;
text mes[MAXN];

int main()
{
    while(scanf("%d",&n)==1&&n!=0){
        int maxlen=0;
        for(int i=1;i<=n;i++){
            scanf("%s %s",mes[i].plain,mes[i].cipher);
            mes[i].len=(int)strlen(mes[i].plain);
            maxlen=max(maxlen,mes[i].len);
        }
        sort(mes+1,mes+1+n);
        char key[MAXN];
        int keylen;
        bool flag;
        for(int k=1;k<=maxlen;k++){
            for(int i=0;i<k;i++)
                key[i]='A'+((26+mes[1].cipher[i]-mes[1].plain[i])%26);
            key[k]='\0';
            flag=true;
            for(int i=1;i<=n;i++){
                for(int index=0;index<mes[i].len;index++){
                    if(index>=k){
                        if((mes[i].plain[index]-'A'+mes[i].cipher[index-k]-'A')%26+'A'!=mes[i].cipher[index]){
                            flag=false;
                            break;
                        }
                    }
                    else{
                        if((mes[i].plain[index]-'A'+key[index]-'A')%26+'A'!=mes[i].cipher[index]){
                            flag=false;
                            break;
                        }
                    }
                }
            }
            if(flag)break;
        }
        if(flag)
            printf("%s\n",key);
        else
            printf("Impossible\n");
    }
    return 0;
}
