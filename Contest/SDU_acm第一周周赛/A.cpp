#include<cstdio>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<double,double> range;
const int MAXN=1010;
const double eps=1e-7;

int main()
{
    int n,d,kase=0,ans,cnt;
    double x,y;
    bool ok;
    range a[MAXN];
    stack<range> s;
    while(scanf("%d %d",&n,&d)==2&&(n!=0||d!=0)){
        ok=true;cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&x,&y);
            if(y<0||y>d||d<0)ok=false;
            if(ok){
                range p;
                p.first=x-sqrt(d*d-y*y);
                p.second=x+sqrt(d*d-y*y);
                a[++cnt]=p;
            }
        }
        if(!ok)
            ans=-1;
        else{
            ans=0;
            sort(a+1,a+1+n);
            for(int i=n;i>=1;i--)
                s.push(a[i]);
            while(!s.empty()){
                range p1,p2;
                p1=s.top();s.pop();
                if(s.empty())
                    ans++;
                else{
                    p2=s.top();s.pop();
                    if(p2.first-p1.second<eps){
                        double right;
                        if(p1.second-p2.second<eps)
                            right=p1.second;
                        else
                            right=p2.second;
                        range p=make_pair(p2.first,right);
                        s.push(p);
                    }
                    else{
                        ans++;
                        s.push(p2);
                    }
                }
            }
        }
        printf("Case %d: %d\n",++kase,ans);
    }
	return 0;
}
