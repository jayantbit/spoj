#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define maxn 1001
#define maxm 5000001
#define inf 1000001
#define bin(a,b)    (!((a)<=0||(a)>n||(b)<=0||(b)>m))
using namespace std;
int n,m,tim,stx,sty,enx,eny,head,tail;short qx[maxm],qy[maxm],x,y,tempx,tempy;char g[maxn][maxn];int dis[maxn][maxn];bool vis[maxn][maxn][8];char dirx[8]={-1,0,0,1,1,1,-1,-1};char diry[8]={0,-1,1,0,-1,1,-1,1};int main(){    scanf("%d",&tim);    while(tim--)    {        scanf("%d %d\n",&n,&m);        for(int i=1;i<=n;i++)        {            for(int j=1;j<=m;j++)            {                g[i][j]=getchar();                if(g[i][j]=='S')                    stx=i,sty=j;                if(g[i][j]=='F')                    enx=i,eny=j,g[i][j]='.';                dis[i][j]=inf+1;                memset(vis[i][j],0,sizeof(vis[i][j]));            }            scanf("\n");        }        head=0,tail=0,qx[0]=stx,qy[0]=sty;        dis[stx][sty]=0;        bool bo=0;        while(head<=tail)        {            x=qx[head],y=qy[head++];            if(x==enx&&y==eny)            {                printf("%d\n",dis[x][y]);                bo=1;                break;            }            tempx=x,tempy=y;            for(int dir=0;dir<8;dir++)            {                vis[x][y][dir]=1;                tempx=x,tempy=y;                while(bin(tempx+dirx[dir],tempy+diry[dir]))                {                    tempx+=dirx[dir],tempy+=diry[dir];                    if(vis[tempx][tempy][dir]||g[tempx][tempy]=='X')                        break;                    vis[tempx][tempy][dir]=1;                    if(dis[tempx][tempy]>inf)                    {                        dis[tempx][tempy]=dis[x][y]+1;                        qx[++tail]=tempx,qy[tail]=tempy;                    }                }            }        }        if(!bo)            printf("-1\n");    }    return 0;}
