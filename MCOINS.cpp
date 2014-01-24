using namespace std;
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
#include<cassert>
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define rep(i,n) for(i=1;i<=n;++i)
#define max(a,b) ((a)>(b))?(a):(b)
typedef  long long int ull;
typedef pair<int,int> pr;


bool dp[1000001][2]={{0}};
int arr[100];

int main()
{
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);


int k,l,m,n,ans,i,mx=-1;
read(k);read(l);read(m);


//memset(dp,0,sizeof(dp));

dp[1][1]=1;dp[0][0]=1;




for(i=0;i<m;i++)
{read(arr[i]);
if(arr[i]>mx)mx=arr[i];
}


for(n=2;n<=mx;n++)
{
	ans=0;
	if(n>=1)ans+=dp[n-1][1];else ans++;
	if(n>=k)ans+=dp[n-k][1];else ans++;
	if(n>=l)ans+=dp[n-l][1];else ans++;
	
	dp[n][0]= (ans==3);
	
	ans=0;
	
	if(n>=1)ans+=dp[n-1][0];
	if(n>=k)ans+=dp[n-k][0];
	if(n>=l)ans+=dp[n-l][0];
	
	
	dp[n][1]=(ans!=0);
}

for(i=0;i<m;i++)
printf("%c",'A'+dp[arr[i]][0]);




}


