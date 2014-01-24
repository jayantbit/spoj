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
#define base 10000
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;


vector <int> vs1,vs2;
int *cnt;
vector <pr> comm;

int main()
{

int n,i,j,ele,s,l,p,q,s1,s2,m,k;
while(cin>>n && n)
{
             s=0;
             assign(cnt,20001);
             
             for(i=0;i<n;i++)
             {
                             cin>>ele;
                             s+=ele;
                             vs1.push_back(s);
                             cnt[ele+base]=i+1;
             }
             
             cin>>m;
             s=0;
             
             for(i=0;i<m;i++)
             {
                             cin>>ele;
                             
                             s+=ele;
                             vs2.push_back(s);
                             if(cnt[ele+base])comm.push_back(make_pair(cnt[ele+base]-1,i));
             }
             i=0;j=0;
              k=comm.size();
             if(comm[k-1].first==n-1 && comm[k-1].second==m-1);
             else { comm.push_back(make_pair(n-1,m-1));k++;}
            
             s=0;
            
             for(l=0;l<k;l++)
             {
                         p=comm[l].first;
                         q=comm[l].second;
                         s1=vs1[p];
                         if(s)s1-=vs1[i];
                         s2=vs2[q];
                         if(s)s2-=vs2[j];
                         //cout<<p<<" "<<q<<" "<<s1<<" "<<s2<<endl;;
                         s+=max(s1,s2);
                         i=p;
                         j=q;
             }
             cout<<s<<endl;
             vs1.clear();
             vs2.clear();
             comm.clear();
}
                 
return 0;
}
