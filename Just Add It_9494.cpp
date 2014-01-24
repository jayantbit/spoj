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
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;
#define mod 10000007

/*
2*(n-1)^k +n^k + 2*(n-1)^n-1 + n^n
*/


ull  pow(ull x){return x*x;}

       ull bigmod(ull b,ull p)
       {

       if (p <= 0) return 1;
       else if (p%2 == 0)
       return pow(bigmod(b,p/2)) % mod;
       else return ((b % mod) * bigmod(b,p-1)) % mod;
       }  


int main()
{
 
 ull n,k,s;
 while(cin>>n>>k && n+k)
 {
                 s=(bigmod(n,n) +2*bigmod(n-1,n-1))%mod;
                 s=(s+bigmod(n,k) +2*bigmod(n-1,k))%mod;
                 cout<<s<<endl;
 }
                 
 
 //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
//system("pause");
return 0;
}
