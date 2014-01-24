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
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;

int arr[100][100]={{0}};

int min4(int a,int b,int c,int d)
{
    set <int> s;
    s.insert(a);s.insert(b);s.insert(c);s.insert(d);
    return *(s.begin());
}
    
    
    
int main()
{
 
int n,m,i,j,ans,t;
cin>>t;
while(t-- && cin>>n>>m)
{
                for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                cin>>arr[i][j];
                
                ans=0;
                for(i=1;i<n-1;i++)
                for(j=1;j<m-1;j++)
                ans+=max(0,min4(arr[i-1][j],arr[i+1][j],arr[i][j+1],arr[i][j-1])-arr[i][j]);
                cout<<ans<<endl;
}
                
                
                
                
 
 //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
getchar();
return 0;
}
