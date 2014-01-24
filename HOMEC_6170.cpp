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

struct st
{ int u,d,pos,w;
  st(int a,int b,int c,int wt)
  {u=a;
  d=b;
  pos=c;
  w=wt;
  }
}temp(0,0,0,0);
         


queue <st> q;
int mu,md,k;
int visited[110][110][2];

int check(int u,int d)
{
 if(u<0 || u>mu)return 0;
 if(d<0 || d>md)return 0;
 if(d>u && u)return 0;
 return 1;  
}   


int bfs()
{
     memset(visited,0,sizeof(visited));
     while(!q.empty())q.pop();
     q.push(st(0,0,0,0));
     
     int u,d,r,x,y,z,c;
     
     while(!q.empty())
     {
               temp=q.front();
               q.pop();
               
               //cout<<temp.u<<" "<<temp.d<<" "<<temp.pos<<" "<<temp.w<<endl;
               
               //for(r=1;r<=k;r++)
               for(u=0;u<=mu && u<=k;u++)
               for(d=0;d<=md  && u+d<=k;d++)
               {
                             if(u+d ==0)continue;
                             if(d>u && u)break;
                            
                             if(temp.u==mu && temp.d==md && temp.pos==1)return temp.w;
                             
                             if(temp.pos==0)
                             {
                             x=temp.u+u;
                             y=temp.d+d;
                             z=1;
                             c=temp.w+1;
                             
                             if(check(x,y) && check(mu-x,md-y) && !visited[x][y][z])
                             {
                              q.push(st(x,y,z,c));
                              visited[x][y][z]=1;
                             
                             }
                             }
                             
                             else
                             {
                             x=temp.u-u;
                             y=temp.d-d;
                             z=0;
                             c=temp.w+1;
                             if(check(x,y) && check(mu-x,md-y) && !visited[x][y][z])
                             {
                              q.push(st(x,y,z,c));
                              visited[x][y][z]=1;
                            
                             }
                             }
               }
     }
   return -1;            
                  
}
                                         
                                            
int main()
{
// freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
 int t,v;
 cin>>t;
 while(t--)
 {
           cin>>mu>>md>>k;
           v=bfs();
           
           cout<<v<<endl;
 }
           
 return 0;
}
