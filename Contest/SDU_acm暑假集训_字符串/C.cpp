#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=21,SIZE=26;

struct trie{
    int cnt;
    trie *child[SIZE];
};

char word[1005][MAXN];
int tot;
trie *root;

trie *create()
{
    trie *tmp=(trie *)malloc(sizeof(trie));
    memset(tmp->child,NULL,sizeof(tmp->child));
    tmp->cnt=0;
    return tmp;
}

void insert(char *s)
{
    trie *p=root;
    while(p!=NULL&&*s!='\0'){
        int id=*s-'a';
        if(p->child[id]==NULL)
            p->child[id]=create();
        p->child[id]->cnt++;
        p=p->child[id];
        s++;
    }
}

int findprefix(char *s)
{
    trie *p=root;
    int i=0;
    while(p!=NULL&&p->cnt!=1&&p->child[s[i]-'a']!=NULL&&s[i]!='\0'){
        p=p->child[s[i]-'a'];
        if(p->cnt==1)return i;
        i++;
    }
    return -1;
}

int main()
{
    char s[MAXN];
    tot=0;
    root=create();
    while(scanf("%s",s)==1){
        tot++;
        int len=strlen(s);
        for(int i=0;i<len;i++)
            word[tot][i]=s[i];
        insert(word[tot]);
    }
    for(int i=1;i<=tot;i++){
        int index=findprefix(word[i]);
        printf("%s ",word[i]);
        if(index==-1)
            printf("%s\n",word[i]);
        else{
            word[i][index+1]='\0';
            printf("%s\n",word[i]);
        }
    }
    return 0;
}
