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
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;

int *ar;

int main()
{
 //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
int n,sum,i,p,m,avg,j;

assign(ar,10000);
while(cin>>n && n!=-1)
{
             sum=0;
             for(i=0;i<n;i++)
             {
                             cin>>ar[i];
                             sum+=ar[i];
             }
             if(sum%n)cout<<"-1\n";
             else {
                  
                                   avg=sum/n;
                                   p=m=0;
                                   for(i=0;i<n;i++)
                                   {
                                                   j=ar[i]-avg;
                                                   if(j<0)m+=-j;
                                                   else p+=j;
                                   }
                              cout<<max(p,m)<<endl;
                  }     
}                                 
                                   

return 0;
}
