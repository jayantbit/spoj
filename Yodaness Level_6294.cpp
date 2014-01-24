#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
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
#define INF INT_MAX
typedef  long long int ull;
using namespace std;


/*
i abcac
j bcd

aaa
aabaaaa


dp[i][j]= min(
              dp[i-1][j-1] // replace
              dp[i-1][j]  //delete
              dp[i][j-1] //insert


//050112-54
//18002008674
//050912-10
              

*/


int dp[3001][3001]={{0}};

string a[30001],b[30001];
int l1,l2;


int min3(int x,int y,int z,int *p)
{ 
   if(x<=y && x<=z){*p=1;return x;}
   if(y<=x && y<=z){*p=2;return y;}
   if(z<=x && z<=y){*p=3;return z;}
    
}

void fn2()
{
    
    
    //abcac
    //bcd
    
    int i,j,p,x=l1,y=l2,k=1;
    
    if(x==0){cout<<y<<endl;return;}
    if(y==0){cout<<x<<endl;return;}
    
    for(i=0;i<=x;i++)dp[i][0]=i;
    for(j=0;j<=y;j++)dp[0][j]=j;
    
    for(i=1;i<=x;i++)
    for(j=1;j<=y;j++)
    if(a[i-1].compare(b[j-1])==0)dp[i][j]=dp[i-1][j-1];
    else dp[i][j]=1+min3(dp[i-1][j-1],dp[i-1][j],dp[i][j-1],&p);
         
     
     cout<<dp[x][y]<<endl;
     
    

}

/*
6
in the force strong you are
you are strong in the force
*/



int main()
{
   //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   
   
   int tt,i,n;
  
   while(cin>>n){
                      l1=l2=n;
                      for(i=0;i<n;i++)cin>>a[i];
                       
                       for(i=0;i<n;i++)cin>>b[i];                     
                                       
                      fn2();
                    }
   
   return 0;
}
