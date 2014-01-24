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
#define MOD 2147483647
typedef  long long int ull;
typedef pair<int,int> pr;


string grid[1000];
ull dp[1000][1000]={{0}};

int visited[1000][1000]={{0}},n;



int check(int x,int y)
{
	if(x<0 || y<0)return 0;
	if(x>=n || y>=n)return 0;
	if(visited[x][y])return 0;
	if(grid[x][y]=='#')return 0;
	visited[x][y]=1;
	return 1;
}

int dfs(int x,int y)
{
	
	visited[x][y]=1;
	int ans=0;
	if(x==n-1 && y==n-1)return 1;
		
	if(check(x,y+1))ans|=dfs(x,y+1);
	if(!ans && check(x+1,y))ans|=dfs(x+1,y);
		
   
   return ans;
	
}

int bfs2()
{
	
	queue <pr> q;
	q.push(make_pair(0,0));
	memset(visited,0, sizeof(visited));
	visited[0][0]=1;
	
	int x,y;
	
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		
		if(x==n-1 && y==n-1)return 1;
		
		if(check(x,y+1))q.push(make_pair(x,y+1));
		if(check(x+1,y))q.push(make_pair(x+1,y));
		if(check(x,y-1))q.push(make_pair(x,y-1));
		if(check(x-1,y))q.push(make_pair(x-1,y));
		
   }
   return 0;
	
}




int main()
{
	
	
	read(n);
	
	int i,j,k,l;
	for(i=0;i<n;i++)
	cin>>grid[i];
	
	memset(dp,0,sizeof(dp));
	
	for(j=n-2;j>=0;j--)
	{
	if(grid[n-1][j]=='#')break;
	 dp[n-1][j]=1;
    }
	
	for(i=n-2;i>=0;i--)
	{
	if(grid[i][n-1]=='#')break;
	 dp[i][n-1]=1;
    }
    
    
    
    for(i=n-2;i>=0;i--)
    for(j=n-2;j>=0;j--)
    if(grid[i][j]=='#')continue;
    else dp[i][j]=(dp[i][j+1]+dp[i+1][j])%MOD;
    
    if(dfs(0,0))cout<<dp[0][0]<<endl;
    else if( bfs2())cout<<"THE GAME IS A LIE\n";
    else cout<<"INCONCEIVABLE\n";
}
	
	
	
	


