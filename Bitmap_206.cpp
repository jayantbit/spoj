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
#define inf 2000000000
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;

/*
........
........
........
........
........
*/


struct node
{
       int x,y,steps;
       node(int a,int b,int f){x=a;y=b;steps=f;}
}temp(0,0,0);       

queue <node> q;

int n,m;

int dis[183][183]={{0}};
char  str[183][183];


void setdis()
{
     int i,j;
     for(i=0;i<n;i++)
     for(j=0;j<m;j++){dis[i][j]=inf;}
     
}



int check(int i,int j,int s)
{
    if(i<0 || i>=n)return 0;
    if(j<0 || j>=m)return 0;
    if(str[i][j]=='1')return 0;
    if(s+1>=dis[i][j])return 0;
    
   
    
    q.push(node(i,j,s+1));
    dis[i][j]=s+1;
    
    return 1;
}
    

int bfs()
{    
     
     while(!q.empty())
     { 
                      temp=q.front();
                      q.pop();
                      check(temp.x+1,temp.y,temp.steps);
                      check(temp.x-1,temp.y,temp.steps);
                      check(temp.x,temp.y+1,temp.steps);
                      check(temp.x,temp.y-1,temp.steps);
     }
return -1;
}                                                            
                      
                      

int main()
{
    
    int i,j,t;
    read(t);
    while(t--)
    {
    
    read(n);read(m);
    
    for(i=0;i<n;i++)
    scanf("%s",&str[i]);
    setdis();
    
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    if(str[i][j]=='1')
         {
        
         q.push(node(i,j,0));
        
         dis[i][j]=0;
         bfs();
         }
    
    for(i=0;i<n;i++)
    {
    for(j=0;j<m;j++)
    {               if(j)printf(" ");
                    printf("%d",dis[i][j]);
    }    
    printf("\n");
    }
    if(t)printf("\n");
    }
    



//system("pause");   
return 0;
}
