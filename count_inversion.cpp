#include<cstdio>
#include<iostream>
using namespace std;



int arr[10001],temp[10001]={0},size,ans;

void merge(int l1,int r1,int l2,int r2)
{
     int cur=0,item,x1=l1,x2=r2,st=l1,sz1=r1-l1+1;
     
     while(l1<=r1 && l2<=r2)
     {
                  if(arr[l1]<=arr[l2])temp[cur++]=arr[l1++];
                  if(arr[l1]>arr[l2]){
                                      temp[cur++]=arr[l2++];
                                      ans+=sz1-(l1-st);
                                      }
                 
        
                  
     }
     
     while(l1<=r1){temp[cur++]=arr[l1];l1++;}
     while(l2<=r2){temp[cur++]=arr[l2];l2++;}
     
     cur=0;
     while(x1<=x2)arr[x1++]=temp[cur++];
     
}


void mergesort(int a,int b)
{
     if(a==b)return;
     int m=(a+b)/2;
     
     mergesort(a,m);
     mergesort(m+1,b);
     merge(a,m,m+1,b);
}
     
     
int main()
{
    int i;
    while(cin>>size && size)
    {
                    for(i=0;i<size;i++)cin>>arr[i];
                    ans=0;
                    mergesort(0,size-1);
    
    //for(i=0;i<size;i++)printf("%d ",arr[i]);
    cout<<ans<<endl;
     }
return 0;
}     
