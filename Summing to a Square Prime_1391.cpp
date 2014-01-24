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
#define MAX 7995
typedef  pair<int,int> pr;
/*
5  2 2 1
3  
*/

  // O((n log n)(log log n))
vector<int> prime(MAX+1,false);
vector<int> cnt(MAX+1,0);  
int dp[MAX][4]={{0}};
vector <int> nums;
 
 
int sieve()
{
     int i;
     prime[0]=prime[1]=true;
     for (i=2; i*i<=MAX; i++)
         if (!prime[i])
         for (int k=i*i; k<=MAX; k+=i)
         prime[k]=true;
}

void gn()
{
     sieve();
     vector <int> v;
     int i,j,k,l;
     for(i=1;i<=90;i++)v.push_back(i*i);
     k=v.size();
     
     for(i=0;i<k;i++)
     for(j=0;j<k;j++)
     {
                     l=v[i]+v[j];
                     if(l<=MAX && !prime[l] && cnt[l]==0 ){nums.push_back(l);cnt[l]=1;}
     }
     sort(nums.begin(),nums.end());
     
     
    // for(i=0;i<k;i++)cout<<nums[i]<<" ";
}
     
     
void fn()
{
     int i=1,n,st;
     for(n=0;n<=3;n++){
                       dp[0][n]=1;
                       if(n)dp[1][n]=1;
                       }
    
    
     
     for(n=2;n<=7994;n++)
     for(st=1;st<=3;st++)
     {dp[n][st]=dp[n][st-1];
     if(st<=n)dp[n][st]+=dp[n-st][st];
     }
}
     
/*
[n][st]
[n-3][3] +n-2
26 3
27 2
28 1
*/     
     


int fn2(int n,int st )
{
  int res=0,i;
  if(n==1 || n==0)return 1;
  if(n<0)return 0;
  for(i=min(st,n);i>=1;i--)res+=fn2(n-i,i);
 return res;
}


int main()
{
 gn();
 fn();
 int n,k,t;
 cin>>t;
 while(t-- && cin>>n>>k)
 cout<<dp[nums[n-1]][k]<<endl;
 

return 0;
}
