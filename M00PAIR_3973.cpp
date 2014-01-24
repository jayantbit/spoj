
#include<stdio.h>
#include<cstdlib>

#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define size 320
typedef  long long int ull;
using namespace std;


/*
a=[]
a.append(0)
a.append(1)
for i in range(2,1001):
   a.append(2*a[i-2]+a[i-1])
while(1):
   try:
      n=int(raw_input(""))
      print a[n-1]
   except:
      break
 */     

char buffer[1000];

class bigint
{
      
      public:
      int *ar;
      
      bigint()
      {
      }
      
      bigint(int i)
      {
                
                 ar=(int*)calloc(size,4);
                 int j=0;
                 while(i)
                 {
                 ar[j++]=i%10;
                 i/=10;
                 }
      }
      
      bigint operator+(bigint y){return plus(y);}    
      bigint operator*(int y){return mult(y);}
        
      bigint   plus(bigint y)
      {
         bigint temp(0);
         int i,j;
         for(i=0;i<size;i++)
         temp.ar[i]=ar[i]+y.ar[i];
         
         for(i=1;i<size;i++)
         {temp.ar[i]+=temp.ar[i-1]/10;
         temp.ar[i-1]%=10;
         }
         
         return temp;
      }
      
      
      bigint mult(int y)
      {
         bigint temp(0);
        
         
         int i,j;
         for(i=0;i<size;i++)temp.ar[i]=ar[i]*y;
         
         for(i=1;i<size;i++)
         {temp.ar[i]+=temp.ar[i-1]/10;
         temp.ar[i-1]%=10;
         }
         
         return temp;
      }
      
     void show()
      {
           int i;
           for(i=size-1;i>=1;i--)if(ar[i])break;
           
         
           for(;i>=0;i--)printf("%d",ar[i]);
           printf("\n");
      }
      
      
};


/*
1
0  1 0
1  0 1
2
2*f(n-2) +f(n-1)
*/



bigint dp[1000];

int main()
{
 
// freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
 
 int i,j,k,c,ti;
 
 
 dp[1]=bigint(0);
 dp[2]=bigint(1);
 for(i=3;i<=999;i++)
 dp[i]=dp[i-2]*2 +dp[i-1];
 
 if(scanf("%d\n",&i)!=EOF)
 dp[i].show();
 else return 0;
 
 
  
  
 k=0;
 
 
   ti = 0;
    while ( (c=fread(buffer, 1, 1000, stdin)) > 0) {
 
        for (j=0;j<c;j++) {
            if (buffer[j] == '\n' || buffer[j] == EOF) {
                 if(ti>=1)dp[ti].show();
                
                ti = 0;
            } else if(buffer[j]>='0' && buffer[j]<='9')ti = ti*10 + (buffer[j] - '0');
            
        }
 
    }
 
 //
//system("pause");
return 0;
}
