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

int seq[100005]={0};
int lpos[26]={0};


int main()
{
	int t,i,j,k,l;
string s;
read(t);
while(t--)
{
	
	cin>>s;
	l=s.length();
	for(i=0;i<26;i++)lpos[i]=-1;
	seq[l]=1;
	for(i=l-1;i>=0;i--)
	{
	  seq[i]=(seq[i+1]*2)%1000000007;
	  j=s[i]-'A';
	  if(lpos[j]!=-1)
	  {
	  
	     seq[i]=(seq[i]-seq[lpos[j]+1]+1000000007)%1000000007;	
	  
	  }
	  lpos[j]=i;
	  
	}
	write(seq[0]);
	
}

//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
}

