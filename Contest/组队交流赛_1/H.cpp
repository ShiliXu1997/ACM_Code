#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=30,MAXM=105;

string s;
int n;
vector<int> connect[MAXN];
bool visited[MAXM];
int xmatch[MAXN],ymatch[MAXM];

bool dfs(int u)
{
    for(int i=0;i<connect[u].size();i++){
        int j=connect[u][i];
        if(!visited[j]){
            visited[j]=true;
            if(ymatch[j]==-1||dfs(ymatch[j])){
                xmatch[u]=j;
                ymatch[j]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans=0;
    memset(xmatch,0xff,sizeof(xmatch));
    memset(ymatch,0xff,sizeof(ymatch));
    for(int i=0;i<s.length();i++)
        if(xmatch[i]==-1){
            memset(visited,false,sizeof(visited));
            if(dfs(i))ans++;
        }
    return ans;
}

int main()
{
    cin>>s>>n;
    int len=s.length();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            char c;
            cin>>c;
            if('a'<=c&&c<='z')
                for(int k=0;k<len;k++)
                    if(s[k]==c)connect[k].push_back(i);
        }
    }
    if(hungary()==len)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
