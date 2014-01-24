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
/*
a +2d
a+(n-3)d
n/2(2a +(n-1)d)
*/

int main()
{
 ull t,a,b,c,n,d,f,i;
 cin>>t;
 while(t-- && cin>>a>>b>>c)
 {
           n=(2*c)/(a+b);
           cout<<n<<endl;
           d=(b-a)/(n-5);
           f=a-2*d;
           for(i=0;i<n;i++)
           {
                           if(i)cout<<" ";
                           cout<<f+i*d;
           }
           cout<<endl;
 }
           
//system("pause");
return 0;
}
