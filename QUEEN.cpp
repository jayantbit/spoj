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



char grid[1000][1001];
int n,m,visited[1000][1000][8]={{{0}}},sx,sy,fx,fy;

int dx[8]={0,0,1,-1,-1,1,-1,1};
int dy[8]={1,-1,0,0,1,-1,-1,1};


struct st
{
	int x,y,dir;
	st(){;}
	st(int a,int b,int c)
	{
		x=a;
		y=b;
		dir=c;
	}
};





 inline int check(int x,int y,int dir,int moves)
{
	if(x<0 || y<0)return 0;
	if(x>=n || y>=m)return 0;
	if(visited[x][y][dir])return 0;
	if(grid[x][y]=='X')return 0;
	visited[x][y][dir]=moves;
	
	return 1;
}


int bfs()
{
	

	queue <st> q;
	
	
	memset(visited,0, sizeof(visited));
	
	int i;
	
	
	check(sx,sy,0,0);
	q.push(st(sx,sy,0));
	
	int ans=INT_MAX;
	int x,y,dir,moves,k=0;
	
	
	while(!q.empty())
	{
		x=q.front().x;
		y=q.front().y;
		dir=q.front().dir;
		
		//cout<<x<<" "<<y<<" "<<dir<<endl;
		
		moves=visited[x][y][dir];
	    
		q.pop();
		
		if(x==fx && y==fy)
		return moves;
	    else {
	    
		
		       	for(i=0;i<8;i++)
		       {
		       	
		       	if(dir%2 && i==dir-1)continue;
		       		if(dir%2==0 && i==dir+1)continue;
		
		              int xx=x,yy=y;
               while(check(xx+dx[i],yy+dy[i],i,moves+1))
			    {
			    	q.push(st(xx+dx[i],yy+dy[i],i));
					xx+=dx[i];
			    	yy+=dy[i];
			    }
                
				}
			   		      
	          }
		
	}
	

    
	
	
	if(ans==INT_MAX)ans=-1;
	else ans--;
	return ans;
	
}

int main()
{
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

int t;
read(t);
while(t--)
{
	read(n);
	read(m);
	
	
	int i,j;
	
	for(i=0;i<n;i++)
	{
		scanf("%s",grid[i]);
	
		
		for(j=0;j<m;j++)
		{
		if(grid[i][j]=='S')
		{
		sx=i;
		sy=j;
	    }
	    else if(grid[i][j]=='F')
	    {
	    	fx=i;
	    	fy=j;
	    }
	     }
  
	    
		
	}
	
	printf("%d\n",bfs());
	
	
}

}


