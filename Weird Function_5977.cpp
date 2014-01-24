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
#define mod 1000000007
typedef  long long int ull;
using namespace std;

/*  
3 4 
2 5
1

1
1 0 0 3
*/



int main()
{
 
int n,sz=0,k,a,b,c,temp,i,t;
ull sum,ele;

read(t);


while(t--)
{
          //read(a);read(b);read(c);read(n);
          cin>>a>>b>>c>>n;
          if(n==1){cout<<"1\n";continue;}
                   
                   priority_queue<int> minh,maxh;
                   sz=0;
                   i=2;
                   while(i<=n)
                   {
                   if(sz==0){maxh.push(1);sum=1;sz++;continue;}
                   
                   
                   ele=(ull)maxh.top();
                  
                   
                        
                   
                   ele=(ele*a + (ull)b*i +c)%mod;     
                   if(ele>maxh.top())minh.push(-ele);
                   else maxh.push(ele);
                   sum+=ele;
                   
                       
                   sz++; 
                   temp=minh.size()- sz/2;
                   if(temp>0 ){maxh.push(-minh.top());minh.pop();}
                   else if(temp<0){minh.push(-maxh.top());maxh.pop();}
                   i++;
                   }      
                             
                   cout<<sum<<endl;
}

//system("pause");
return 0;
}

