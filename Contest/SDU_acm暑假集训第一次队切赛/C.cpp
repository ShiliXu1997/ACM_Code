#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=50002;

char s[MAXN];
int t,len;
bool ok[32][32];
bool dp[MAXN];

void init()
{
    memset(ok,false,sizeof(ok));
    ok['h'-'a'][30]=true;ok['h'-'a']['e'-'a']=true;
    ok['l'-'a']['i'-'a']=true;ok['b'-'a']['e'-'a']=true;ok['b'-'a'][30]=true;ok['c'-'a'][30]=true;
    ok['n'-'a'][30]=true;ok['o'-'a'][30]=true;ok['f'-'a'][30]=true;ok['n'-'a']['e'-'a']=true;
    ok['n'-'a']['a'-'a']=true;ok['m'-'a']['g'-'a']=true;ok['a'-'a']['l'-'a']=true;ok['s'-'a']['i'-'a']=true;
    ok['p'-'a'][30]=true;ok['s'-'a'][30]=true;ok['c'-'a']['l'-'a']=true;ok['a'-'a']['r'-'a']=true;
    ok['k'-'a'][30]=true;ok['c'-'a']['a'-'a']=true;ok['s'-'a']['c'-'a']=true;ok['t'-'a']['i'-'a']=true;
    ok['v'-'a'][30]=true;ok['c'-'a']['r'-'a']=true;ok['m'-'a']['n'-'a']=true;ok['f'-'a']['e'-'a']=true;
    ok['c'-'a']['o'-'a']=true;ok['n'-'a']['i'-'a']=true;ok['c'-'a']['u'-'a']=true;ok['z'-'a']['n'-'a']=true;
    ok['g'-'a']['a'-'a']=true;ok['g'-'a']['e'-'a']=true;ok['a'-'a']['s'-'a']=true;ok['s'-'a']['e'-'a']=true;
    ok['b'-'a']['r'-'a']=true;ok['k'-'a']['r'-'a']=true;ok['r'-'a']['b'-'a']=true;ok['s'-'a']['r'-'a']=true;
    ok['y'-'a'][30]=true;ok['z'-'a']['r'-'a']=true;ok['n'-'a']['b'-'a']=true;ok['m'-'a']['o'-'a']=true;
    ok['t'-'a']['c'-'a']=true;ok['r'-'a']['u'-'a']=true;ok['r'-'a']['h'-'a']=true;ok['p'-'a']['d'-'a']=true;
    ok['a'-'a']['g'-'a']=true;ok['c'-'a']['d'-'a']=true;ok['i'-'a']['n'-'a']=true;ok['s'-'a']['n'-'a']=true;
    ok['s'-'a']['b'-'a']=true;ok['t'-'a']['e'-'a']=true;ok['i'-'a'][30]=true;ok['x'-'a']['e'-'a']=true;
    ok['c'-'a']['s'-'a']=true;ok['b'-'a']['a'-'a']=true;ok['h'-'a']['f'-'a']=true;ok['t'-'a']['a'-'a']=true;
    ok['w'-'a'][30]=true;ok['r'-'a']['e'-'a']=true;ok['o'-'a']['s'-'a']=true;ok['i'-'a']['r'-'a']=true;
    ok['p'-'a']['t'-'a']=true;ok['a'-'a']['u'-'a']=true;ok['h'-'a']['g'-'a']=true;ok['t'-'a']['l'-'a']=true;
    ok['p'-'a']['b'-'a']=true;ok['b'-'a']['i'-'a']=true;ok['p'-'a']['o'-'a']=true;ok['a'-'a']['t'-'a']=true;ok['r'-'a']['n'-'a']=true;
    ok['f'-'a']['r'-'a']=true;ok['r'-'a']['a'-'a']=true;ok['r'-'a']['f'-'a']=true;ok['d'-'a']['b'-'a']=true;
    ok['s'-'a']['g'-'a']=true;ok['b'-'a']['h'-'a']=true;ok['h'-'a']['s'-'a']=true;ok['m'-'a']['t'-'a']=true;
    ok['d'-'a']['s'-'a']=true;ok['r'-'a']['g'-'a']=true;ok['c'-'a']['n'-'a']=true;ok['f'-'a']['l'-'a']=true;ok['l'-'a']['v'-'a']=true;
    ok['l'-'a']['a'-'a']=true;ok['c'-'a']['e'-'a']=true;ok['p'-'a']['r'-'a']=true;ok['n'-'a']['d'-'a']=true;
    ok['p'-'a']['m'-'a']=true;ok['s'-'a']['m'-'a']=true;ok['e'-'a']['u'-'a']=true;ok['g'-'a']['d'-'a']=true;
    ok['t'-'a']['b'-'a']=true;ok['d'-'a']['y'-'a']=true;ok['h'-'a']['o'-'a']=true;ok['e'-'a']['r'-'a']=true;
    ok['t'-'a']['m'-'a']=true;ok['y'-'a']['b'-'a']=true;ok['l'-'a']['u'-'a']=true;
    ok['a'-'a']['c'-'a']=true;ok['t'-'a']['h'-'a']=true;ok['p'-'a']['a'-'a']=true;ok['u'-'a'][30]=true;
    ok['n'-'a']['p'-'a']=true;ok['p'-'a']['u'-'a']=true;ok['a'-'a']['m'-'a']=true;ok['c'-'a']['m'-'a']=true;
    ok['b'-'a']['k'-'a']=true;ok['c'-'a']['f'-'a']=true;ok['e'-'a']['s'-'a']=true;ok['f'-'a']['m'-'a']=true;
    ok['m'-'a']['d'-'a']=true;ok['n'-'a']['o'-'a']=true;ok['l'-'a']['r'-'a']=true;
}

int main()
{
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        len=strlen(s);
        memset(dp,false,sizeof(dp));
        dp[len]=true;
        for(int i=len-1;i>=0;i--){
            if(dp[i+1]&&ok[s[i]-'a'][30])dp[i]=true;
            if(dp[i+2]&&ok[s[i]-'a'][s[i+1]-'a'])dp[i]=true;
        }
        if(dp[0])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
