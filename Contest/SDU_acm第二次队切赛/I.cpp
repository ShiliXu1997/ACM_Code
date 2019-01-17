#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

const int MAXN=1005;

int t;
char str[MAXN];
set<char> mirlet;

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int main()
{
    mirlet.insert('A');mirlet.insert('H');
    mirlet.insert('I');mirlet.insert('M');
    mirlet.insert('O');mirlet.insert('T');
    mirlet.insert('U');mirlet.insert('V');
    mirlet.insert('W');mirlet.insert('X');
    mirlet.insert('Y');
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int len=strlen(str);
        int ans=0,cnt=0;
        for(int i=0;i<len;i++)
            if(mirlet.count(str[i]))cnt++;
        if(cnt==0)
            printf("%d\n",ans);
        else{
            for(int i=0;i<len;i++)
                for(int j=0;j<len;j++){
                    int temp=0;
                    if(mirlet.count(str[i])&&str[i]==str[j]){
                        int id=i,jd=j;
                        while(id<=jd){
                            if(!mirlet.count(str[id])||str[id]!=str[jd]){
                                temp=1;
                                break;
                            }
                            else{
                                if(id==jd)
                                    temp+=1;
                                else
                                    temp+=2;
                                id++;
                                jd--;
                            }
                        }
                    }
                    else
                        temp=1;
                    ans=max(ans,temp);
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}

