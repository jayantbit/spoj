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

int ways[1000001]={0};


int main()
{
	string s;
	int l,i,j,k;
	while(cin>>s && s.compare("0"))
	{
		
		l=s.length();
		memset(ways,0,sizeof(ways));
		ways[l]=1;
		for(i=l-1;i>=0;i--)
		{
			if(s[i]=='0')continue;
			ways[i]=ways[i+1];
			if( i!=l-1 && ((s[i]-'0')*10 +s[i+1]-'0')<=26 )ways[i]+=ways[i+2];
			
		}
		write(ways[0]);
		
	}
	return 0;
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
}

