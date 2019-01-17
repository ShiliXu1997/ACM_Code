#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=105;

struct food{
    string name;
    int price;
    bool operator < (const food &another)const{
        return price<another.price;
    }
};

food app[MAXN],mai[MAXN],des[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int s,m,d;
        string str;
        scanf("%d %d %d",&s,&m,&d);
        for(int i=1;i<=s;i++){
            cin>>app[i].name;
            scanf("%d",&app[i].price);
        }
        for(int i=1;i<=m;i++){
            cin>>mai[i].name;
            scanf("%d",&mai[i].price);
        }
        for(int i=1;i<=d;i++){
            cin>>des[i].name;
            scanf("%d",&des[i].price);
        }
        sort(app+1,app+1+s);
        sort(mai+1,mai+1+m);
        sort(des+1,des+1+d);
        int ans=0,mida,midm,midd;
        string stra,strm,strd;
        mida=(s%2==0?app[(1+s)/2+1].price:app[(1+s)/2].price);
        midm=(m%2==0?mai[(1+m)/2+1].price:mai[(1+m)/2].price);
        midd=(d%2==0?des[(1+d)/2+1].price:des[(1+d)/2].price);
        ans=mida+midm+midd;
        stra=(s%2==0?app[(1+s)/2+1].name:app[(1+s)/2].name);
        strm=(m%2==0?mai[(1+m)/2+1].name:mai[(1+m)/2].name);
        strd=(d%2==0?des[(1+d)/2+1].name:des[(1+d)/2].name);
        printf("%d ",ans);
        cout<<stra<<" "<<strm<<" "<<strd<<endl;
    }
    return 0;
}
