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
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define rep(i,n) for(i=1;i<=n;++i)
#define max(a,b) ((a)>(b))?(a):(b)
typedef  long long int ull;
typedef pair <int,int> pr;




 

int adj[16][4]={{9,5,3,2},{10,6,4,1},{11,7,4,1},{12,8,3,2},{13,7,6,1},{14,8,5,2},{15,8,5,3},{16,7,6,4},{13,11,10,1},{14,12,9,2},{15,12,9,3},{16,10,4,2},{15,14,9,5},{16,13,10,6},{16,13,11,7},{15,14,12,8}};
int sz[16]={4,3,3,2,3,2,2,1,3,2,2,1,2,1,1,0};
 
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
 
 
#define get getchar
 
 
inline long long int inp()
{
    long long int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9')
    {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=get();
    }
    return n*s;
}
 

int visited[65537]={0};
int rem[65537][4]={{0}};

int bit(int num,int a,int b)
{
	a=15-a;
	b=15-b;
	return  ((num&(1<<a))>>a) ^ ((num&(1<<b))>>b);
}

int bit(int num,int a)
{
return  ( (num&(1<<a))>>a );
}




int flip(int num,int a,int b)
{
	a=15-a;
	b=15-b;
	return num^(1<<a | 1<<b);
}




int dfs(int num,int step=0 )
{
	
	int i,j,num2,ans=4,temp;
	
	if(num==255)return 0;
    if(step==3)return ans;
	if(rem[num][step])return rem[num][step];
	
	for(i=0;i<15;i++)
	for(j=0;j<sz[i];j++)
	if( bit(num,i,adj[i][j]-1) )
		{
			
			num2=flip(num,i,adj[i][j]-1);
			if(!visited[num2])
			{
			temp=1+dfs(num2,step+1);
			ans=min(ans,temp);
		    }
		}
	visited[num]=1;
	rem[num][step]=ans;
	return ans;
}
		
	
	



int main()
{
 //freopen("out.txt","r",stdin);freopen("out3.txt","w",stdout);
 
int i,j,k,t,tt=1,base,num;

t=inp();
int v[16];
for(tt=1;tt<=t;tt++)
{
	for(i=0;i<16;i++)read(v[i]);
	
	num=0;base=1;
	
	for(i=15;i>=0;i--)
	{
	num+=base*v[i];
    base*=2;
    }
	
	
	j=dfs(num);
	printf("Case #%d: ",tt);
	if(j!=4)write(j);
	else printf("more\n");
	memset(visited,0,sizeof(visited));
	
}
return 0;
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
}

