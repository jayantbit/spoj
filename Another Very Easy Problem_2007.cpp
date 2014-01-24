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
#define max 5001
typedef  pair<int,int> pr;


    

int dp[max][max]={{0}};


int solve(int x,int y)
{
    if(x<0)return 0;
    if(y==1)return 1;
    if(dp[x][y])return dp[x][y];
    int r=0,c;
    for(c=x/y;c>=0;c--)r=(r+solve(x-c*y,y-1))%1988;
    dp[x][y]=r;
    return dp[x][y];
}    


int main()
{
 int n,k;
while(cin>>n>>k && n+k)
cout<<solve(n-k,k)<<endl;
return 0;
}
