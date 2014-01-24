#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<sstream>
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define base 1000
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;

int *cnt;

int main()
{
int n,i,ele,f,ans,t;
read(t);
while(t--)
{
             read(n);
             assign(cnt,2001);
             f=0;
             for(i=0;i<n;i++)
             {
                             read(ele);
                             if(++cnt[ele+base]>n/2){
                                                     f=1;
                                                     ans=ele;
                                                     }
             }
             if(f)printf("YES %d\n",ans);
             else printf("NO\n");
}                                        
             
 //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

return 0;
}
