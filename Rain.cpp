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

int s[1500000],t[1500000],a[1500000],sum[1500000];


int main()
{
	
	int tt,i,j,k,n,m;
	read(tt);
	while(tt--)
	{
		read(s[0]);
		read(t[0]);
		read(n);
		read(m);
	    
		sum[0]=a[0]=(s[0]%100 + 1)*(t[0]%100 + 1);
	
		
		for(i=1;i<n;i++)
		{
			s[i] = (78901 + 31*s[i-1])%699037;
            t[i] = (23456 + 64*t[i-1])%2097151;
            a[i]=(s[i]%100 + 1)*(t[i]%100 + 1);
            sum[i]=sum[i-1]+a[i];
		   
		}
		
		
		int ans=n+1;
		i=0;
		do
		{
		j=lower_bound(sum+i,sum+n,m+sum[i]-a[i])-(sum);
	    ans=min(ans,j-i);
	    i++;
	    }while(i<=n-ans);
		
		/*
		for(i=0,j=0;i<n && j<n;)
		if(sum[j]-sum[i]+a[i] <m)j++;
		else {
			    ans=min(ans,j-i);
			    i++;
			}
		*/	
		write(ans);
		
	}
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
}

