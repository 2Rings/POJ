//因为每次都有可能改变了地形，所以不能用bfs,只能用DFS遍历所有路径，同时用step<11来剪枝
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef class
{
    public:
        int row;
        int col;
        int status;
}Location;

Location S, E;
int Board[30][30];
const int inf =11;
int Min_Step;
int step,w,h;
void B_DFS(int i, int j, int d, bool status, bool flag, int step)
{
    if(step>10)
        return;
    
    if(Board[i][j]==3)
    {
        if(Min_Step>step)
            Min_Step=step;
        return;
    }

    
    if(flag)
    {
        switch(d)
        {
            case 0:{Board[i-1][j]=0;break;}
            case 1:{Board[i][j-1]=0;break;}
            case 2:{Board[i+1][j]=0;break;}
            case 3:{Board[i][j+1]=0;break;}
        }
    }
        
    
    if(!status)
    {
        if((i-1>=1)&&(Board[i-1][j]==0||Board[i-1][j]==3))
        {
            B_DFS(i-1,j,0,true,false,step+1);
        }
        if((j-1>=1)&&(Board[i][j-1]==0||Board[i][j-1]==3))
        {
            B_DFS(i,j-1,1,true,false,step+1);
        }
        if((i+1<=h)&&(Board[i+1][j]==0||Board[i+1][j]==3))
        {
            B_DFS(i+1,j,2,true,false,step+1);
        }
        if((j+1<=w)&&(Board[i][j+1]==0||Board[i][j+1]==3))
        {
            B_DFS(i,j+1,3,true,false,step+1);
        }
    }
    else if(status)
    {
        switch(d)
        {
            case 0:
            {
                if(i-1<1)
                    return;
                else
                {
                    if(Board[i-1][j]==0)
                {
                    B_DFS(i-1,j,0,true,false,step);
                }
                else if(Board[i-1][j]==1)
                {                   
                    B_DFS(i,j,0,false,true,step);
                }
                else if(Board[i-1][j]==3)
                {                   
                    B_DFS(i-1,j,0,false,false,step);
                }

                }
                
                break;                  
            }
            case 1:
            {
                if(j-1<1)
                    return;
                else
                {
                    if(Board[i][j-1]==0)
                {
                    B_DFS(i,j-1,1,true,false,step);
                }
                else if(Board[i][j-1]==1)
                {
                    B_DFS(i,j,1,false,true,step);
                }
                else if(Board[i][j-1]==3)
                {                   
                    B_DFS(i,j-1,1,false,false,step);
                }
                }
                break;                 
            }
            case 2:
            {
                if(i+1>h)
                    return;
                else
                {
                    if(Board[i+1][j]==0)
                {
                    B_DFS(i+1,j,2,true,false,step);
                }
                else if(Board[i+1][j]==1)
                {
                    B_DFS(i,j,2,false,true,step);
                }
                else if(Board[i+1][j]==3)
                {                   
                    B_DFS(i+1,j,2,false,false,step);
                }
                }
                
                break;                  
            }
            case 3:
            {
                if(j+1>w)
                    return;
                else
                {
                    if(Board[i][j+1]==0)
                {
                    B_DFS(i,j+1,3,true,false,step);
                }
                else if(Board[i][j+1]==1)
                {
                    B_DFS(i,j,3,false,true,step);
                }
                else if(Board[i][j+1]==3)
                {                   
                    B_DFS(i,j+1,3,false,false,step);
                }
                }
                break;                  
            }
        }
   
    }
    if(flag)
    {
        switch(d)
        {
            case 0:{Board[i-1][j]=1;break;}
            case 1:{Board[i][j-1]=1;break;}
            case 2:{Board[i+1][j]=1;break;}
            case 3:{Board[i][j+1]=1;break;}
        }        
    }
    return;
}

int main()
{
    while(cin>>w>>h)
    {
        if(!w&&!h)
            break;
        
        Min_Step=inf;

        for(int i=1;i<=h;i++)
        {
            for(int j=1; j<=w;j++)
            {
                cin>>Board[i][j];
                if(Board[i][j]==2)
                {
                    S.row=i;
                    S.col=j;
                    S.status=false;
                    Board[i][j]=0;
                }
                if(Board[i][j]==3)
                {
                    E.row=i;
                    E.col=j;
                }             
            }
        }

        B_DFS(S.row,S.col,0,S.status,false,0);
        if(Min_Step<inf)
            cout<<Min_Step<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}