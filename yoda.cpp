using namespace std;
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
#define max(a,b) ((a)>(b))?(a):(b)
typedef  long long int ull;
#define MOD 9223372036854775807ll

ull ncr[1000][1000]={{0}};

int freq[40]={0};


//2 1
//1 1 1 0
int main()
{
	
int i,j,n,r,l;

for(n=0;n<1000;n++)ncr[n][0]=1;

for(r=1;r<1000;r++)
for(n=r;n<1000;n++)
ncr[n][r]=(ncr[n-1][r]+ncr[n-1][r-1])%MOD;


string str;
while(getline(cin,str))
{
	memset(freq,0,sizeof(freq));
	l=str.length();
	int odds=0,oddpos=-1;
	for(i=0;i<l;i++)
	{
		if(str[i]>='a' && str[i]<='z')freq[str[i]-'a']++;
		if(str[i]>='A' && str[i]<='Z')freq[str[i]-'A']++;
		if(str[i]>='0' && str[i]<='9')freq[26+str[i]-'0']++;
	}
	int total=0;
	for(i=0;i<40;i++)
	{
		total+=freq[i];
		if(freq[i]%2){odds++;oddpos=i;}
	}
	
	if(total%2==0 && odds){cout<<"0\n";continue;}
	if(total%2==1)
	{if(odds>1){cout<<"0\n";continue;}
	else {freq[oddpos]--;total--;}
    }
	cout<<".";
	
	ull ans=1;
	total/=2;
	for(i=0;i<40;i++)
	{
	//cout<<total<<" "<<freq[i]/2<<endl;
	ans*=ncr[total][freq[i]/2];total-=freq[i]/2;
	}
	cout<<ans<<endl;
	
	
}
	
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);


}

