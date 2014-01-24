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

vector <int> a,b;
int *c[4000];

    
int main()
{
 //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
 string str;
 int x,y,i,j,ele,ans,t;
 
 getline(cin,str);
 stringstream s1(str);
 s1>>t;
 
 
 while(t--)
 {
 ans=0;
 getline(cin,str);
 stringstream s2(str);
 while(s2>>ele && ele)a.push_back(ele);
 x=a.size();
 
 while(getline(cin,str) && str[0]!='0')
 {
                        
                        stringstream s3(str);
                        while(s3>>ele && ele)b.push_back(ele);
                        
                        y=b.size();
                        
                        for(i=0;i<x;i++)assign(c[i],y);
                        
                        
                        c[0][0]=(a[0]==b[0]);
                        
                        if(a[0]==b[1])c[0][1]=1;
                        else c[0][1]=c[0][0];
                        
                        if(a[1]==b[0])c[1][0]=1;
                        else c[1][0]=c[0][0];
                        
                        
                        for(i=1;i<x;i++) // first string
                        for(j=1;j<y;j++) //second string
                        if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
                        else c[i][j]=max(c[i-1][j],c[i][j-1]);
                        
                        ans=max(ans,c[x-1][y-1]);
                        b.clear();
 }
                        
    
    
cout<<ans<<endl;
a.clear();
}


//system("pause");
return 0;
}
