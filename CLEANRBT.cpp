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
#define INF INT_MAX
typedef  long long int ull;
typedef pair<int,int> pr;

char grid[20][20];

vector < pr > dirt;

int dist[11][11];
int ind[20][20]={{0}},w,h,len;

int visited[20][20]={{0}};

int f[11][2048]={{0}};




int check(int x,int y,int d)
{
	if(x<0 || y<0)return 0;
	
	if( x>=h || y>=w)return 0;
	if(visited[x][y])return 0;
	if(grid[x][y]=='x')return 0;
	
	
	visited[x][y]=1;
	return 1;
}

int bfs(int i)
{
	
	memset(visited,0,sizeof(visited));
	queue <pair <pr,int> > q;
	
    int x=dirt[i].first,y=dirt[i].second,d;
	
	visited[x][y]=1;
	q.push(make_pair(dirt[i],0));
	
	int j=0;
	while(!q.empty())
	{
		x=q.front().first.first;
		y=q.front().first.second;
		d=q.front().second;
		q.pop();
		if(ind[x][y])
		{ dist[i][ind[x][y]-1]=d;
		   j++;
		   if(j==(len))break;
	    }
		
		
		if(check(x,y+1,d+1))q.push(make_pair(make_pair(x,y+1),d+1));
		if(check(x,y-1,d+1))q.push(make_pair(make_pair(x,y-1),d+1));
		if(check(x+1,y,d+1))q.push(make_pair(make_pair(x+1,y),d+1));
		if(check(x-1,y,d+1))q.push(make_pair(make_pair(x-1,y),d+1));
	
		
		
   }
   
  
   
   
	
}

int fn(int n,int mask)
{
	
	if(mask==((1<<len) -1))return 0;
	if(f[n][mask])return f[n][mask];
	int i,j,k=INF;
	for(i=0;i<len;i++)
	{
	if(mask&(1<<i))continue;
	if(dist[n][i]!=-1)
	{j=fn(i,mask|(1<<i));
	 if(j!=INF)
	 k=min(k,dist[n][i]+j);
    }
    }
	return  f[n][mask]=k;
	
}
int main()
{
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

int i,j,k,l;

while(scanf("%d%d",&w,&h)!=EOF && w+h)
{
	
	int flag=1;
	
	for(i=0;i<h;i++)
	scanf("%s",grid[i]);
	
	k=0;
	
	for(i=0;i<h && flag;i++)
	for(j=0;j<w;j++)
	if(grid[i][j]=='o')
	{
		dirt.push_back(make_pair(i,j));
        ind[i][j]=++k;
        flag=0;
        break;
	}
	
	  
	  for(i=0;i<h;i++)
	  for(j=0;j<w;j++)
      if(grid[i][j]=='*')
	  {  
  	    dirt.push_back(make_pair(i,j));
        ind[i][j]=++k;
      }
    len=k;
    
    for(i=0;i<len;i++)
    for(j=0;j<len;j++)
    dist[i][j]=-1;
    
    
    for(i=0;i<len;i++)
    bfs(i);
    
    
    
    
    i=fn(0,1);
    
	if(i!=INF)printf("%d\n",i);
	else printf("-1\n");
    
    dirt.clear();
    memset(ind,0,sizeof(ind));
    memset(f,0,sizeof(f));
}
}
