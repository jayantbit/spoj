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


int w[100],*dp[100],*cnt;




int main()
{
int t,n,i,sum,j,ans;
cin>>t;
while(t--)
{
          cin>>n;
          sum=0;
          for(i=0;i<n;i++){
                           read(w[i]);
                           sum+=w[i];
                           }
          
          for(i=0;i<n;i++)assign(dp[i],sum+1);
          
          
          for(j=w[0];j<=sum;j++)dp[0][j]=w[0];
          
          
          
          for(i=1;i<n;i++)
          for(j=0;j<=sum;j++)
          {
                             if(w[i]>j)dp[i][j]=dp[i-1][j];
                             else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
          }                       
          
          assign(cnt,sum+1);
          ans=0;
          for(j=sum;j>=1;j--)
          {
                             i=dp[n-1][j];
                             if(!cnt[i]){
                                         cnt[i]=1;
                                         ans+=i;
                                         }
          }
          write(ans);
                         
}                          
return 0;
}
