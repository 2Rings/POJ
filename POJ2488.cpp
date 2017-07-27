#include<iostream>
#include<string.h>
#include <stdlib.h>

using namespace std;

typedef class
{
    public:
        int row;
        char col;
}Location;

int x,y;

void path(int i, int j, int num)
{
    switch(num)
    {
        case 1:{x=i-1;y=j-2;break;}
        case 2:{x=i+1;y=j-2;break;}
        case 3:{x=i-2;y=j-1;break;}
        case 4:{x=i+2;y=j-1;break;}
        case 5:{x=i-2;y=j+1;break;}
        case 6:{x=i+2;y=j+1;break;}
        case 7:{x=i-1;y=j+2;break;}
        case 8:{x=i+1;y=j+2;break;}
    } 
    return;
}

int p,q;
int chess['Z'+1][27];

bool DFS(Location* way, int i, int j, int step)
{
     chess[i][j]=true;
     way[step].row=i;
     way[step].col=j;
     if(step==way[0].row)
         return true;
     for(int k=1; k<=8; k++)
     {
         path(i,j,k);
         int ii=x;
         int jj=y;
         if(!chess[ii][jj]&&ii>=1&&ii<=26&&jj>='A'&&jj<='A'+q-1)
             if(DFS(way,ii,jj,step+1))
             return true;
     }
     chess[i][j]=false;
     return false;
}

int main()
{
    int test;
    cin>>test;
    int t=1;
    while(t<=test)
    {
        memset(chess,false,sizeof(chess));
        cin>>p>>q;
        if(p==1&&q==1)
        {
            cout<<"Scenario #"<<t++<<':'<<endl;
            cout<<"A1"<<endl<<endl;
            continue;
        }
        if(p*q>26||p>=9||q>=9||p<=2||q<=2)
        {
            cout<<"Scenario #"<<t++<<':'<<endl;
            cout<<"impossible"<<endl<<endl;
            continue;
        }
        
        Location* way=new Location[p*q+1];
        way[0].row=p*q;
        
        bool flag=false;
        for(int j='A';j<='A'+q-1;j++)
        {
           for(int i=1;i<=p;i++)
               if(DFS(way,i,j,1))
               {
                   cout<<"Scenario #"<<t++<<':'<<endl;
                   
                   for(int k=1;k<=way[0].row;k++)
                       cout<<way[k].col<<way[k].row;
                   cout<<endl<<endl;
                   flag=true;
                   break;
                }
                if(flag)
                   break;
        }      
        if(!flag)
        {
            cout<<"Scenario #"<<t++<<':'<<endl;
            cout<<"impossible"<<endl<<endl;
        }
    }
    system("pause");
    return 0;
}
         
