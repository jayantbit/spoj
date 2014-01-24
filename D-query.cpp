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

//abaccaab
//abbcdfefghuik
//l1 r1
//l2 r2

//1 1 1 2 3
//1 1 2 1 3
//1 1 2 2 3
// 1 1 2 1 3
// 1 1 1 2 3 

vector <int> st[131072];

//11234
//23344

void fn(int node,int n1,int n2)
{
	int x=st[n1].size(),y=st[n2].size(),i=0,j=0;
	
	

	
	while(i<x && j<y)
	{
	    if(st[n1][i]<st[n2][j]){st[node].push_back(st[n1][i]);i++; while(i<x && st[n1][i]==st[n1][i-1])i++;}
		else if(st[n2][j]<st[n1][i]){st[node].push_back(st[n2][j]);j++;while(j<y && st[n2][j]==st[n2][j-1])j++;}
		else if(st[n1][i]==st[n2][j]){st[node].push_back(st[n1][i]);i++;j++;while(i<x && st[n1][i]==st[n1][i-1])i++;while(j<y && st[n2][j]==st[n2][j-1])j++;}
	}
	
	while(i<x)
	{ 
	  st[node].push_back(st[n1][i]);i++;
	  while(i<x && st[n1][i]==st[n1][i-1])i++;
	}
	while(j<y)
	{ 
	  st[node].push_back(st[n2][j]);j++;
	  while(j<y && st[n2][j]==st[n2][j-1])j++;
	}
}



vector<int> fn(vector<int> *a,vector<int> *b)
{
	int x=(*a).size(),y=(*b).size(),i=0,j=0;
	vector <int> ans;
	

	
	while(i<x && j<y)
	{
	    if((*a)[i]<(*b)[j]){ans.push_back((*a)[i]);i++; while(i<x && (*a)[i]==(*a)[i-1])i++;}
		else if((*b)[j]<(*a)[i]){ans.push_back((*b)[j]);j++;while(j<y && (*b)[j]==(*b)[j-1])j++;}
		else if((*a)[i]==(*b)[j]){ans.push_back((*a)[i]);i++;j++;while(i<x && (*a)[i]==(*a)[i-1])i++;while(j<y && (*b)[j]==(*b)[j-1])j++;}
	}
	
	while(i<x)
	{ 
	  ans.push_back((*a)[i]);i++;
	  while(i<x && (*a)[i]==(*a)[i-1])i++;
	}
	while(j<y)
	{ 
	  ans.push_back((*b)[j]);j++;
	  while(j<y && (*b)[j]==(*b)[j-1])j++;
	}
	return ans;
}

int val[30000]={0};

void makeTree(int node , int s, int e )
{
 if( s == e ) 
 {
  st[node].push_back(val[s]);
  return ;
 }
 int md = ( s + e ) / 2;
 int n1 = ( 2 * node ) + 1;
 int n2 = n1 + 1;
 makeTree( n1, s , md ) ;
 makeTree( n2, md + 1, e );
 fn(node,n1,n2);
}

vector <int> ret ;
vector<int> makeQuery( int node, int s, int e, int r1, int r2 ) 
{
 
 
 if( e < r1 || s > r2 ) return ret;
 if( s >= r1 && e <= r2 ) return st[ node ];
 int n1 = ( 2 * node ) + 1;
 int n2 = ( 2 * node ) + 2;
 int md = ( s + e ) / 2;
 vector<int> v1 = makeQuery( n1, s, md , r1, r2 );
 vector<int> v2 = makeQuery( n2, md + 1, e, r1, r2 );
 if( v1.size()==0 ) return v2;
 else if( v2.size()==0 ) return v1;
 	int x=v1.size(),y=v2.size(),i=0,j=0;
	vector <int> ans;
	

	
	while(i<x && j<y)
	{
	    if(v1[i]<v2[j]){ans.push_back(v1[i]);i++; while(i<x && v1[i]==v1[i-1])i++;}
		else if(v2[j]<v1[i]){ans.push_back(v2[j]);j++;while(j<y && v2[j]==v2[j-1])j++;}
		else if(v1[i]==v2[j]){ans.push_back(v1[i]);i++;j++;while(i<x && v1[i]==v1[i-1])i++;while(j<y && v2[j]==v2[j-1])j++;}
	}
	
	while(i<x)
	{ 
	  ans.push_back(v1[i]);i++;
	  while(i<x && v1[i]==v1[i-1])i++;
	}
	while(j<y)
	{ 
	  ans.push_back(v2[j]);j++;
	  while(j<y && v2[j]==v2[j-1])j++;
	}
	return ans;
	
}
//200000
 //30000
 
/*
 1 5
 1 8
 1 10
 2 3
 2 11
 2 15
 */


int main()
{

 
          
          
	freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

int n,t,i,q,y,x;
read(n);
for(i=0;i<n;i++)
read(val[i]);
makeTree(0,0,n-1);
read(q);
while(q--)
{
	read(x);
	read(y);
	write(makeQuery(0,0,n-1,x-1,y-1).size());
}


return 0;
}

